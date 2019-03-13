##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC = gcc                                # C compiler
CFLAGS = -fPIC -Wall -Wextra -g         # C flags
LDFLAGS = -shared                       # linking flags
RM = rm -f                              # rm command
TARGET_LIB = libmy_malloc.so            # target lib

SRCS =			free.c				\
       			malloc.c			\
       			realloc.c

DEPS = header.h
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@
include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)