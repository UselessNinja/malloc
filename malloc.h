/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** malloc
*/

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#ifndef MALLOC_H_
#define MALLOC_H_

typedef enum boolean {
    false,
    true
} bool;

typedef struct header_malloc_s {
    size_t size;
    bool is_free;
    struct header_malloc_s *next;
} header_malloc_t;

header_malloc_t *start;
header_malloc_t *end;
pthread_mutex_t lock;

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

#endif /* !MALLOC_H_ */
