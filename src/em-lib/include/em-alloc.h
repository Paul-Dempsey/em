#pragma once
#ifndef EM_ALLOC_H_INCLUDED
#define EM_ALLOC_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

// application must define allocators

/// @brief Allocate memory (equivalent to C malloc())
void * AllocMemory(unsigned int size);
/// @brief Reallocate a memory block (equivalent to C realloc())
void * ReAllocMemory(void * mem, unsigned int size);
/// @brief Free memory (equivalent to C free())
void FreeMemory(void * mem);

#ifdef __cplusplus
}
#endif
#endif