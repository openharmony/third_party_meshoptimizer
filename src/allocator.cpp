// This file is part of meshoptimizer library; see meshoptimizer.h for version/license details
// MIT License

// Copyright (c) 2016-2024 Arseny Kapoulkine
#include "meshoptimizer.h"

void meshopt_setAllocator(void* (MESHOPTIMIZER_ALLOC_CALLCONV* allocate)(size_t), void (MESHOPTIMIZER_ALLOC_CALLCONV* deallocate)(void*))
{
	meshopt_Allocator::Storage::allocate = allocate;
	meshopt_Allocator::Storage::deallocate = deallocate;
}
