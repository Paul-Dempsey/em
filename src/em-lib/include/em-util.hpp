// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_UTIL_H_INCLUDED
#define EM_UTIL_H_INCLUDED
#include <stdint.h>

inline bool hiBit(uint8_t v) { return v & 0x80; }
inline void zero_bytes(void* data, size_t count) {
    uint8_t* poke = (uint8_t*)data;
    for (auto i = 0; i < count; ++i) {
        *poke++ = 0;
    }
}
#endif