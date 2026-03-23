#include "internal.h"

block_header *merge_backward(block_header *block) {
	if (block->prev && block->prev->is_free) {
		block->prev->size += sizeof(block_header) + block->size;
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

block_header *merge_forward(block_header *block) {
	if (block->next && block->next->is_free) {
		block->size += sizeof(block_header) + block->next->size;
		block->next = block->next->next;
		if (block->next) {
			block->next->prev = block;
		} else {
			heap_end = block;
		}
	}

	return block;
}