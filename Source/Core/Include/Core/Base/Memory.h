#pragma once

#ifdef LOOM_MEMORY_IMPLEMENTATION

#include <mutex>
#include <tracy/Tracy.hpp>

//----------------------------------------
// Basic Tracy implementation (page 43/130 - tracy documentation)
//----------------------------------------
std::mutex memoryLock;

void* operator new(std::size_t count)
{
    std::lock_guard lock(memoryLock);
    auto ptr = malloc(count);
    TracyAlloc(ptr, count);
    return ptr;
}

void operator delete(void* ptr) noexcept
{
    std::lock_guard lock(memoryLock);
    TracyFree(ptr);
    free(ptr);
}

#endif