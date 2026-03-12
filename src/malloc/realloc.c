#include "internal.h"
#include "string.h"

void *realloc(void *ptr, size_t size) {
	if (!ptr) return malloc(size);
	if (size == 0) {
		free(ptr);
		return NULL;
	}
	struct block_header *block = (struct block_header *)ptr - 1;
	size_t aligned_size = ALIGN(size);
	if (block->size >= aligned_size) return ptr;
	size_t total_available =
		(block->size + sizeof(struct block_header) + block->next->size);
	if (block->next && block->next->is_free &&
		total_available >= aligned_size) {
		merge_forward(block);
		return ptr;
	}
	void *new =  malloc(size);
	if(!new) return NULL;
	memcpy(new, ptr, block->size);
	free(ptr);
	return new;
}