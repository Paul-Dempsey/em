// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_PEDAL_H_INCLUDED
#define EM_PEDAL_H_INCLUDED

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum PedalType {
    PedalType_None = 0,
    PedalType_Switch = 1,
    PedalType_Expression = 2,
    PedalType_Damper = 3,
    PedalType_TriValue = 4,
    PedalType_CV = 5,
    PedalType_Potentiometer = 6,
} PedalType;

typedef enum PedalId {
    PedalId_One = 0,
    PedalId_Two = 1,
} PedalId;

typedef struct PedalInfo {
    uint8_t value;
    uint8_t cc;
    uint8_t min;
    uint8_t max;
    uint8_t kind; // PedalType
    uint8_t jack; // PedalId
} PedalInfo;

void init_pedal(PedalInfo* pedal, uint8_t jack);
void reset_pedal(PedalInfo* pedal);

#ifdef __cplusplus
} // extern "C"
#endif
#endif