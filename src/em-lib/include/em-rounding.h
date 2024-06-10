// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_ROUNDING_H_INCLUDED
#define EM_ROUNDING_H_INCLUDED
#include <stdint.h>

#include "em-tuning.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum RoundKind {
    RoundKind_Normal,
    RoundKind_Release,
    RoundKind_Y,
    RoundKind_InverseY,
}RoundKind;

typedef enum RoundEqual {
    RoundEqual_Disabled,
    RoundEqual_Enabled,
    RoundEqual_Equal,
} RoundEqual;

typedef struct Rounding {
    uint8_t rate;
    uint8_t initial; // (bool)
    uint8_t kind;
    uint8_t tuning;
    uint8_t equal;
} Rounding;

#ifdef __cplusplus
} // extern "C"
#endif
#endif