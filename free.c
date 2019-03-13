/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** bttffree
*/

#include "malloc.h"

void delete_pointers()
{
    header_malloc_t *buffer;

    buffer = start;
    while (buffer) {
        if(buffer->next == end) {
            buffer->next = NULL;
            end = buffer;
        }
        buffer = buffer->next;
    }
}

void free(void *ptr)
{
    header_malloc_t *header;
    void *pbrk;

    if (!ptr)
        return;
    header = (header_malloc_t*)ptr - 1;
    pbrk = sbrk(0);
    if ((char*)ptr + header->size == pbrk) {
        if (start == end) {
            start = NULL;
            end = NULL;
        } else {
            delete_pointers();
        }
        sbrk(0 - sizeof(header_malloc_t) - header->size);
    } else {
        header->is_free = true;
    }
    return;
}