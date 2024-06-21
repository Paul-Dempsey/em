// Copyright (C) Paul Chase Dempsey
//
// C interface to the Eagan Matrix
//
#pragma once
#ifndef EM_MATRIX_H_INCLUDED
#define EM_MATRIX_H_INCLUDED
#include <stdint.h>
#include "em-hardware.h"
#include "em-pedal.h"
#include "midi-message.h"

#ifdef __cplusplus
extern "C" {
#endif

void* CreateMatrix();
uint64_t MatrixSize();

uint8_t EaganMatrixReceiveMidi(void* matrix, PackedMidiMessage message);

void SetMidiOutput(void* matrix, void* context, MidiHandler handler);

uint16_t FirmwareVersion(void* matrix);
uint16_t CvcVersion(void* matrix);
uint8_t Hardware(void* matrix);
uint8_t GetMidiRate(void* matrix);

void RequestConfiguration(void* matrix);
void RequestUserPresets(void* matrix);
void RequestSystemPresets(void* matrix);
void NextSysPreset(void* matrix);
void PreviousSysPreset(void* matrix);
void RefineCalibration(void* matrix);
void ResetCalibration(void* matrix);

/// @brief Set the MIDI transmission rate of the device
/// @param matrix EM pointer
/// @param rate 1, 3, 20 for 1/1 (Full), 1/3 (Medium), 1/20 (Slow, Bluetooth)
/// @return Rate that was set.
/// If the returned rate differs from _rate_, then the value passed was invalid.
/// Calls the MidiOutput callback.
uint8_t SetMidiRate(void* matrix, uint8_t rate);

void GetPedal(void* matrix, PedalId id, PedalInfo* pedal);
const char * GetPresetName(void* matrix);
const char * GetPresetText(void* matrix);
//uint16_t MacroValue(void* matrix, uint8_t macro);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
