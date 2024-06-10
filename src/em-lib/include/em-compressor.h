// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_COMPRESSOR_H_INCLUDED
#define EM_COMPRESSOR_H_INCLUDED
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Compressor {
    uint8_t threshold;  // EMCC_CompressorThreshold  = cc 90;
    uint8_t attack;     // EMCC_CompressorAttack     = cc 91;
    uint8_t ratio;      // EMCC_CompressorRatio      = cc 92;
    uint8_t mix;        // EMCC_CompressorMix        = cc 93;
} Compressor;

void ResetCompressor(Compressor* self);

#ifdef __cplusplus
} // extern "C"
#endif
#endif