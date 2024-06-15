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
    R8orKind_ShortReverb,
    R8orKind_ModDelay,
    R8orKind_SweptEcho,
    R8orKind_AnalogEcho,
    R8orKind_DigitalEchoLPF,
    R8orKind_DigitalEchoHPF,
    R8orKind_LongReverb,
} R8orKind;

#define R8OR_Mask   0x07
#define R8OR_Extend 0x40

typedef enum R8orValue {
    R8orValue_R1,
    R8orValue_R2,
    R8orValue_R3,
    R8orValue_R4,
    R8orValue_R5,
    R8orValue_R6,
    R8orValue_RMix,
} R8orValue;

typedef struct Recirculator {
    uint8_t kind;    // R8orKind
    uint8_t disable; // bool
    uint8_t extend;  // bool
} Recirculator;

void InitDefault(Recirculator* recirculator);
const char * RecirculatorName(R8orKind kind);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
