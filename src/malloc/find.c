#include "internal.h"

struct block_header *find_free(size_t size) {
  struct block_header *current = heap_start;

  while (current) {
    if (current->is_free == 1 && current->size >= size) {
      if (current->size >= (size + sizeof(struct block_header) + 16))
        split(current, size);
      return current;
    }
    current = current->next;
  }

  return NULL;
}