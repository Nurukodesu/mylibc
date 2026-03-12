#include "unistd.h"
#include "internal.h"

struct block_header *heap_start = NULL;
struct block_header *heap_end = NULL;

static struct block_header *request_data(size_t size) {
  void *p = sbrk(size + sizeof(struct block_header));
  if (p == (void *)-1)
    return NULL;
  struct block_header *block = (struct block_header *)p;
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
  struct block_header *block;
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