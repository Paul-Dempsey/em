// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_MATRIX_H_INCLUDED
#define EM_MATRIX_H_INCLUDED
#include <stdint.h>
#include "em-common.h"
#include "midi-message.h"

#ifdef __cplusplus
extern "C" {
#endif

void* CreateMatrix(EM_ALLOCATE ally);
int EaganMatrixReceiveMidi(void* matrix, PackedMidiMessage message);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
