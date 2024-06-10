// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_HARDWARE_H_INCLUDED
#define EM_HARDWARE_H_INCLUDED
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum EM_Hardware {
    EM_Hardware_Unknown,
    EM_Hardware_LightFull,      // light action full, not UP version
    EM_Hardware_LightHalf,      // light action, not UP version
    EM_Hardware_ClassicFull,    // classic action full size
    EM_Hardware_ClassicHalf,    // classic action half size
    EM_Hardware_Mini,           // ContinuuMini
    EM_Hardware_Osmose49,       // Osmose
    EM_Hardware_Slim22,         // slim 22L6x
    EM_Hardware_Slim46,         // slim 46L6x
    EM_Hardware_Slim70,         // slim 70L6x
    EM_Hardware_EMM,            // Eurorack EaganMatrix Module
    EM_Hardware_LightFullUp,    // light action full, UP triple-dsp board
    EM_Hardware_LightHalfUp,    // light action half, UP triple-dsp board 
} EM_Hardware;

const char * HardwarePresetClass(EM_Hardware hw);
const char * ShortHardwareName(EM_Hardware hw);
const char * HardwareName(EM_Hardware hw);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
