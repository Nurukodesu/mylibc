#include "internal.h"

struct block_header *merge_backward(struct block_header *block) {
	if (block->prev && block->prev->is_free) {
		block->prev->size += sizeof(struct block_header) + block->size;
		block->prev->next = block->next;
		if (block->next) {
			block->next->prev = block->prev;
		} else {
			heap_end = block->prev;
		}
		block = block->prev;
	}
	return block;
}

struct block_header *merge_forward(struct block_header *block) {
	if (block->next && block->next->is_free) {
		block->size += sizeof(struct block_header) + block->next->size;
		block->next = block->next->next;
		if (block->next) {
			block->next->prev = block;
		} else {
			heap_end = block;
		}
	}

	return block;
}