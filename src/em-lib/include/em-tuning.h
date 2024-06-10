// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_TUNING_H_INCLUDED
#define EM_TUNING_H_INCLUDED
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum TuningGrid {
    Tuning_Equal = 0,
    Tuning_nTone_First = 1,
    Tuning_nTone_Last = 50,
    Tuning_JustC = 60,
    Tuning_JustCs = 61,
    Tuning_JustD = 62,
    Tuning_JustEb = 63,
    Tuning_JustF = 64,
    Tuning_JustFs = 65,
    Tuning_JustG = 66,
    Tuning_JustAb = 67,
    Tuning_JustA = 68,
    Tuning_JustBb = 69,
    Tuning_JustB = 70,
    Tuning_User_First = 80,
    Tuning_User_Last = 87,
} TuningGrid;

#ifdef __cplusplus
} // extern "C"
#endif
#endif