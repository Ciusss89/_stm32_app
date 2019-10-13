/*
 * Author (c) 2019 Giuseppe Tipaldi
 *
 */

#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>
#include <stddef.h>

struct buffer {
	char *data;
	size_t lenght;
};

/* @buffer_init:
 *
 *  example:
 *  struct buffer *buff;
 *  ..
 *  buff = buffer_init(64);
 *  ..
 *  buffer_clean(buff);
 */
struct buffer *buffer_init(size_t size);

/* @buffer_clean: kill the buffer
 *
 */
void buffer_clean(struct buffer *b);

#endif
