#include "internal.h"

void free(void *ptr) {
  struct block_header *block = (struct block_header *)ptr - 1;
  block->is_free = 1;
  merge_forward(merge_backward(block));
}