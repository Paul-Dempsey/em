// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef MIDI_FILE_H_INCLUDED
#define MIDI_FILE_H_INCLUDED
#include <stdint.h>
#include "midi-message.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum MidiFileError {
    MF_Ok,
    MF_InvalidMidiFile,
    MF_InsufficientData,

} MidiFileError;

/// @brief Parse the data of a MIDI file
/// @param length Length of MIDI file data.
/// @param bytes MIDI file data. Must be a complete MIDI file.
/// @param handlerContext Companion data for the handler function
/// @param handlerFn Function to handle the stream of MIDI contained in the file.
/// @return MF_Ok on a successful parse. 
MidiFileError ParseMidiFileData(uint32_t length, uint8_t* bytes, void *handlerContext, MidiHandler handlerFn);

#ifdef __cplusplus
} // extern "C"
#endif
#endif