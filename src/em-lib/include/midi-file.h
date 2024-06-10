// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef MIDI_FILE_H_INCLUDED
#define MIDI_FILE_H_INCLUDED
#include <stdint.h>
#include "midi-message.h"

#ifdef __cplusplus
extern "C" {
#endif

void ParseMidiFileData(uint32_t length, uint8_t bytes[], void *handlerContext, MidiHandler handlerFn);

#ifdef __cplusplus
} // extern "C"
#endif
#endif