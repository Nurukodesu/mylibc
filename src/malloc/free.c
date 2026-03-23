#include "internal.h"

void free(void *ptr) {
  block_header *block = (block_header *)ptr - 1;
  block->is_free = 1;
  merge_forward(merge_backward(block));
}