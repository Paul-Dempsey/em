#include <assert.h>
#include "../include/midi-message.h"

inline bool hiBit(uint8_t v) { return 0 != (v & 0x80); }

PackedMidiMessage MakeRaw(uint8_t status, uint8_t channel, uint8_t value1, uint8_t value2) {
    assert(0 == (status & CHANNEL_MASK));
    assert(channel < 16);
    assert(!hiBit(value1));
    assert(!hiBit(value2));
    PackedMidiMessage m = {0};
    m.status_byte = status | channel;
    m.data1 = value1;
    m.data2 = value2;
    return m;
}

