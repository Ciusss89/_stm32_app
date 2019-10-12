/*
 * Author (c) 2019 Giuseppe Tipaldi
 *
 */

#ifndef API_H
#define API_H

#include <stdlib.h>
#include <stddef.h>

struct buffer {
	char *data;
	size_t lenght;
};

/* @_malloc: like malloc but check if a pointer is not null
 *
 */
void *_malloc(size_t size);

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
