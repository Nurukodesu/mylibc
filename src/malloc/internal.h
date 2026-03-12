#pragma once
#include "stddef.h"
#include "malloc.h"

#define ALIGN(size) (((size) + 15) & ~15)

struct block_header{
    size_t size;
    int is_free;
    int padding;
    struct block_header *prev, *next;
};

extern struct block_header *heap_start;
extern struct block_header *heap_end;

extern struct block_header *find_free(size_t size);
extern void split(struct block_header *block, size_t size);
extern struct block_header *merge_forward(struct block_header *block);
extern struct block_header *merge_backward(struct block_header *block);