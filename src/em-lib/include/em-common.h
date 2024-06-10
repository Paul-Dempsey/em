// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_COMMON_H_INCLUDED
#define EM_COMMON_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef void * (*EM_ALLOCATE)(size_t size);
typedef void (*EM_DEALLOCATE)(void * mem);

#ifdef __cplusplus
} // extern "C"
#endif
#endif