#include "internal.h"

void split(struct block_header *block, size_t size) {
  struct block_header *new =
      (struct block_header *)((char *)(block + 1) + size);
  new->next = block->next;
  new->prev = block;
  new->size = block->size - size - sizeof(struct block_header);
  new->is_free = 1;

  block->next = new;
  block->size = size;

  if (!new->next)
    new->next->prev = new;
  if (block == heap_end)
    heap_end = new;
}
