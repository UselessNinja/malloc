/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** bttfmalloc
*/

#include "malloc.h"

header_malloc_t *look_for_available_memory(size_t size)
{
    header_malloc_t *temp = start;
    while (temp != NULL) {
        if (temp->is_free == true && temp->size >= size)
            return temp;
        temp = temp->next;
    }
    return (NULL);
}

void update_header (header_malloc_t *header, size_t size)
{
    header->size = size;
    header->is_free = false;
    header->next = NULL;
    if (!start)
        start = header;
    if (end)
        end->next = header;
    end = header;
}

void *malloc(size_t size)
{
    size_t size_used;
    void *memory_block;
    header_malloc_t *header;

    if (!size)
        return (NULL);
    header = look_for_available_memory(size);
    if (header != NULL) {
        header->is_free = false;
        return (void*)(header + 1);
    }
    size_used = (sizeof(header_malloc_t) + size);
    memory_block = sbrk(size_used);
    if (memory_block == (void*) - 1)
        return (NULL);
    header = memory_block;
    update_header(header, size);
    return (void*)(header + 1);
}