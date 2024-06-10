// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_RECIRCULATOR_H_INCLUDED
#define EM_RECIRCULATOR_H_INCLUDED
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Kind of R[ecirculat]or (R8or)
typedef enum R8orKind {
    R8orType_ShortReverb,
    R8orType_ModDelay,
    R8orType_SweptEcho,
    R8orType_AnalogEcho,
    R8orType_DigitalEchoLPF,
    R8orType_DigitalEchoHPF,
    R8orType_LongReverb,
} R8orKind;

#define R8OR_Mask   0x07
#define R8OR_Extend 0x40

typedef struct Recirculator {
    uint8_t kind;    // R8orKind
    uint8_t disable; // bool
    uint8_t extend;  // bool
} Recirculator;

#ifdef __cplusplus
} // extern "C"
#endif
#endif
