/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** bttfrealloc
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    header_malloc_t *header;
    void *reallocated_memory;

    if (!ptr && size != 0)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    header = (header_malloc_t*)ptr - 1;
    if (header->size >= size)
        return ptr;
    reallocated_memory = malloc(size);
    if (reallocated_memory) {
        memcpy(reallocated_memory, ptr, header->size);
        free(ptr);
    }
    return (reallocated_memory);
}