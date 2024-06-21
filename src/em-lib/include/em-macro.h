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
    M2MError_Error,

} MacroToMidiError;

/// @brief For a given macro number and value for that macro, generate MIDI to send.
/// @param macro_number Macro number from 1-90
/// @param value Signed 14-bit value for the number, in the range -8192 .. 8191 for macros 7-90 or 0..16,256 for i..vi
/// @param data buffer to insert MidiMessages. Must be at least 2 messages long
/// @return M2MError_Ok (0) on success, or a MacroToMidiError code
int MacroToMidiData(uint8_t macro_number, int16_t value, PackedMidiMessage* data);

/// @brief For a given macro number and value for that macro, call handler with the MIDI to send to the device
/// @param macro_number Macro number from 1-90
/// @param value Signed 14-bit value for the number, in the range -8192 .. 8191
/// @param handlerContext  Client handler context
/// @param handlerFn Midi handler function
/// @return 0 on success, 
int MacroToMidi(uint8_t macro_number, int16_t value, void *handlerContext, MidiHandler handlerFn);

/// @brief 1-based macro number for the macro cc, considering hi_bank == true for macro 49-90
/// @param macro_cc Macro CC number
/// @param hi_bank false = macros 1-48, true = macros 49-90
/// @return 0 if CC not a macro cc
uint8_t MacroNumber(uint8_t macro_cc, bool hi_bank);

/// @brief CC for the macro number
/// @param macro_number 
/// @return CC for the macro number
uint8_t MacroNumberCC(uint8_t macro_number);

#ifdef __cplusplus
} // extern "C"
#endif

#endif