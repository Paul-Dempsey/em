// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_MATRIX_H_INCLUDED
#define EM_MATRIX_H_INCLUDED
#include <stdint.h>
#include "midi-message.h"

#ifdef __cplusplus
extern "C" {
#endif

void* CreateMatrix();
uint64_t MatrixSize();

int EaganMatrixReceiveMidi(void* matrix, PackedMidiMessage message);

void SetPreserveSurface(void* matrix, uint8_t preserve);
void SetPreservePedal(void* matrix, uint8_t preserve);
void SetPreserveMidiEncoding(void* matrix, uint8_t preserve);
uint8_t GetPreserveSurface(void* matrix);
uint8_t GetPreservePedal(void* matrix);
uint8_t GetPreserveMidiEncoding(void* matrix);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
