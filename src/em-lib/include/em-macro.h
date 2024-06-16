// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_MACRO_H_INCLUDED
#define EM_MACRO_H_INCLUDED
#include <stdint.h>
#include "midi-message.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef enum MacroToMidiError {
    M2MError_Ok = 0,
    M2MError_InvalidMacroNumber = 1,
    M2MError_Underflow = 2,
    M2MError_Overflow = 3,

} MacroToMidiError;

/// @brief For a given macro number and value for that macro, call handler with the MIDI to send to the device
/// @param macro_number Macro number from 1-90
/// @param value Signed 14-bit value for the number, in the range -8192 .. 8191
/// @param handlerContext  Client handler context
/// @param handlerFn Midi handler function
/// @return 0 on success, 
int MacroToMidi(uint8_t macro_number, int16_t value, void *handlerContext, MidiHandler handlerFn);

#ifdef __cplusplus
} // extern "C"
#endif

#endif