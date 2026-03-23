#pragma once
#include "stddef.h"
#include "stdlib.h"

#define ALIGN(size) (((size) + 15) & ~15)

typedef struct block_header{
    size_t size;
    int is_free;
    int padding;
    struct block_header *prev, *next;
} block_header;

extern block_header *heap_start;
extern block_header *heap_end;

extern block_header *find_free(size_t size);
extern void split(block_header *block, size_t size);
extern block_header *merge_forward(block_header *block);
extern block_header *merge_backward(block_header *block);