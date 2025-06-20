﻿#include "PCH.h"

#include "AnimBoxCore/Memory/Public/Memory.h"
#include "AnimBoxCore/Core/Public/Logger.h"

void AnimBox::AllocationMetrics::LogAllocationMetrics() const
{
    LOG_MESSAGE("Memory usage: %u bytes. Allocated: %u, freed: %u", 
        GetCurrentUsage(), TotalAllocated, TotalFreed)
}

void* operator new(size_t size)
{
#ifdef AB_DEBUG
    AnimBox::AllocationMetrics::GetHeapAllocationMetrics().TotalAllocated += size;
#endif
    
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
#ifdef AB_DEBUG
    AnimBox::AllocationMetrics::GetHeapAllocationMetrics().TotalFreed += size;
#endif
    
    free(memory);
}