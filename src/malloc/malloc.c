#include "unistd.h"
#include "internal.h"

block_header *heap_start = NULL;
block_header *heap_end = NULL;

static block_header *request_data(size_t size) {
  void *p = sbrk(size + sizeof(block_header));
  if (p == (void *)-1)
    return NULL;
  block_header *block = (block_header *)p;
  block->size = size;
  block->is_free = 0;
  block->next = NULL;
  block->prev = heap_end;
  return block;
}

void *malloc(size_t size) {
  if (!size)
    return NULL;
  size_t aligend_size = ALIGN(size);
  block_header *block;
  if (heap_start == NULL) {
    block = request_data(aligend_size);
    if (!block)
      return NULL;
    heap_start = heap_end = block;
  } else {
    block = find_free(aligend_size);
    if (block) {
      block->is_free = 0;
    } else {
      block = request_data(aligend_size);
      if (!block)
        return NULL;
      heap_end->next = block;
      block->prev = heap_end;
      heap_end = block;
    }
  }
  return (void *)(block + 1);
}