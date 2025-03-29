// SPDX-License-Identifier: BSD-3-Clause
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
		return NULL;
	return ret;
}
void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);
    if (ptr) {
        memset(ptr, 0, total_size);
    }
    return ptr;
}
void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr != NULL) {
        size_t size = *((size_t *)ptr - 1);
        munmap(ptr - sizeof(size_t), size + sizeof(size_t));
    }
    //https://stackoverflow.com/
}
void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL) {
        return malloc(size);
    }
    void *newptr = malloc(size);
    if (newptr != NULL) {
        memcpy(newptr, ptr, size);
        free(ptr);
    }
    return newptr;
}
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size = nmemb * size;
    void *new_ptr = realloc(ptr, total_size);
    if (new_ptr == NULL) {
        return NULL;
    }
    return new_ptr;
}
