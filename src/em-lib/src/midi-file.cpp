// Copyright (C) Paul Chase Dempsey
#include "../include/midi-file.h"
#include "../include/em-util.hpp"
#include "../include/midi-message.h"

enum class BufferError {
    Ok,
    VariableLengthOutOfRange,
    EndOfData,
};

struct Buffer {
    size_t size;
    uint8_t* data;
    uint32_t pos;
    uint32_t read_count;
    bool counting;

    void Init(uint32_t length, uint8_t *bytes) {
        size = length;
        data = bytes;
        pos = 0;
        counting = false;
        read_count = 0;
    }
    void Reset() {
        pos = read_count = 0;
        counting = false;
    }
    inline void StartCounting() {
        counting = true;
    }
    inline void StopCounting() {
        counting = false;
    }
    inline void ResetCount() {
        read_count = 0;
    }
    inline uint32_t GetCount() {
        return read_count;
    }
    inline uint8_t* Head() { return data + pos; }
    inline uint8_t* End() { return data + size; }

    BufferError ReadByte(uint8_t * dest)
    {
        if (pos >= size) return BufferError::EndOfData;
        *dest = data[pos++];
        if (counting) read_count++;
        return BufferError::Ok;
    }

    BufferError Read(uint8_t* bytes, uint32_t count)
    {
        if (count + pos > size) return BufferError::EndOfData;
        auto scan = Head();
        for (auto i = 0; i < count; ++i) {
            *bytes++ = *scan++;
        }
        pos += count;
        if (counting) read_count += count;
        return BufferError::Ok;
    }

    BufferError Skip(uint32_t count)
    {
        if (count + pos > size) return BufferError::EndOfData;
        pos += count;
        if (counting) read_count += count;
        return BufferError::Ok;
    }

    BufferError ReadU16(uint16_t* result)
    {
        uint8_t buf[2];
        BufferError e;
        uint8_t* scan = &buf[0];
        if (BufferError::Ok != (e = Read(&scan[0], 2))) return e;
        uint32_t r = *scan++;
        r = (r << 8) | *scan;
        *result = r;
        return BufferError::Ok;
    }

    BufferError ReadU32(uint32_t* result)
    {
        uint8_t buf[4];
        BufferError e;
        uint8_t* scan = &buf[0];
        if (BufferError::Ok != (e = Read(scan, 4))) return e;
        uint32_t r = *scan++;
        r = (r << 8) | *scan++;
        r = (r << 8) | *scan++;
        r = (r << 8) | *scan;
        *result = r;
        return BufferError::Ok;
    }

    BufferError ReadVariableLength(uint32_t* result)
    {
        uint32_t acc = 0;
        int count = 0;
        BufferError e;
        while (true) {
            uint8_t v;
            if (BufferError::Ok != (e = ReadByte(&v))) return e;
            acc = (acc << 7) | (v & 0x7f);
            if (!hiBit(v)) break;
            count++;
        }
        if (count >= 4) return BufferError::VariableLengthOutOfRange;
        *result = acc;
        return BufferError::Ok;
    }

    BufferError SkipVariableLength()
    {
        BufferError e;
        uint32_t length;
        if (BufferError::Ok != (e = ReadVariableLength(&length))) return e;
        return Skip(length);
    }


};

bool same(uint32_t length, uint8_t* const b1, uint8_t* const b2)
{
    for (uint32_t i = 0; i < length; ++i) {
        if (b1[i] != b2[i]) return false;
    }
    return true;
}

MidiFileError ParseMidiFileData(uint32_t length, uint8_t* bytes, void *handlerContext, MidiHandler handlerFn)
{
    BufferError e;
    Buffer buffer;
    uint8_t chunk[4];
    buffer.Init(length, bytes);

    if (BufferError::Ok != (e = buffer.Read(chunk, 4))) return MidiFileError::MF_InvalidMidiFile;
    if (!same(4, chunk, (uint8_t*)"MThd")) {
        return MidiFileError::MF_InvalidMidiFile;
    }
    uint32_t header_size;
    if (BufferError::Ok != (e = buffer.ReadU32(&header_size))) return MidiFileError::MF_InsufficientData;

    uint16_t u16;

    // format: expect format 0 or 1
    if (BufferError::Ok != (e = buffer.ReadU16(&u16))) return MidiFileError::MF_InsufficientData;
    if (u16 > 1) return MidiFileError::MF_InvalidMidiFile;

    // track count: expect 1 in an EM preset
    if (BufferError::Ok != (e = buffer.ReadU16(&u16))) return MidiFileError::MF_InsufficientData;
    if (u16 != 1) return MidiFileError::MF_InvalidMidiFile;

    // clock resolution: unimportant for EM
    if (BufferError::Ok != (e = buffer.Skip(2))) return MidiFileError::MF_InsufficientData;

    // This could be an error, but let's be tolerant and skip the rest of any larger header
    if (header_size > 6) {
        if (BufferError::Ok != (e = buffer.Skip(header_size - 6))) return MidiFileError::MF_InsufficientData;
    }

    // next chunk should be the track
    if (BufferError::Ok != (e = buffer.Read(chunk, 4))) return MidiFileError::MF_InvalidMidiFile;
    if (!same(4, chunk, (uint8_t*)"MTrk")) {
        return MidiFileError::MF_InvalidMidiFile;
    }

    uint32_t track_size;
    if (BufferError::Ok != (e = buffer.ReadU32(&track_size))) return MidiFileError::MF_InsufficientData;

    // remaining data is preset data
    buffer.StartCounting();
    uint8_t running_status = 0;
    uint32_t u32;
    while (true) {
        // we ignore message timing in EM presets
        if (BufferError::Ok != (e = buffer.ReadVariableLength(&u32))) {
            return e == BufferError::EndOfData ? MidiFileError::MF_InsufficientData : MidiFileError::MF_InvalidMidiFile;
        }

        uint8_t first_byte;
        if (BufferError::Ok != (e = buffer.ReadByte(&first_byte))) return MidiFileError::MF_InsufficientData;

        if (!hiBit(first_byte)) {
            uint8_t status = running_status & 0xF0;
            uint8_t second_byte = 0;
            if (!((status == 0xC0) || (status == 0xD0))) {
                if (BufferError::Ok != (e = buffer.ReadByte(&second_byte))) return MidiFileError::MF_InsufficientData;
            }
            auto msg = MakeRawBase(running_status, first_byte, second_byte);
            if (handlerFn(handlerContext, msg)) return MidiFileError::MF_Stopped;
            continue;
        }

        switch (first_byte) {
            case 0xF0: // SysEx
            case 0xF7: // End SysEx
                if (BufferError::Ok != (e = buffer.SkipVariableLength())) {
                    return e == BufferError::EndOfData ? MidiFileError::MF_InsufficientData : MidiFileError::MF_InvalidMidiFile;
                }
                break;

            case 0xFF: { // Meta event
                uint8_t meta_type, meta_length;
                if (BufferError::Ok != (e = buffer.ReadByte(&meta_type))) return MidiFileError::MF_InsufficientData;
                if (BufferError::Ok != (e = buffer.ReadByte(&meta_length))) return MidiFileError::MF_InsufficientData;
                switch (meta_type) {
                    case 0x2f: // End of track
                       return MidiFileError::MF_Ok;

                    default: 
                        if (BufferError::Ok != (e = buffer.SkipVariableLength())) {
                            return e == BufferError::EndOfData ? MidiFileError::MF_InsufficientData : MidiFileError::MF_InvalidMidiFile;
                        }
                        break;
                }
            } break;

            default: {
                running_status = first_byte;
                uint8_t status = first_byte & 0xF0;
                uint8_t b1;
                uint8_t b2 = 0;
                if (BufferError::Ok != (e = buffer.ReadByte(&b1))) return MidiFileError::MF_InsufficientData;
                if (!((status == 0xC0) || (status == 0xD0))) {
                    if (BufferError::Ok != (e = buffer.ReadByte(&b2))) return MidiFileError::MF_InsufficientData;
                }
                auto msg = MakeRawBase(first_byte, b1, b2);
                if (handlerFn(handlerContext, msg)) return MidiFileError::MF_Stopped;
           }
        }
    }
    return MidiFileError::MF_Ok;
}