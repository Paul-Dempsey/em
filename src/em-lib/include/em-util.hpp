// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_UTIL_H_INCLUDED
#define EM_UTIL_H_INCLUDED
#include <stdint.h>

inline bool hiBit(uint8_t v) { return 0 != (v & 0x80); }
inline void zero_bytes(uint8_t* data, size_t count) {
    for (auto i = 0; i < count; ++i) {
        *data++ = 0;
    }
}
#endif