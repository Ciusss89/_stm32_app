#include "api.h"

void *_malloc(size_t size)
{
	void *pt = malloc(size ? size : 1);
	if (pt == NULL)
		abort();
	return pt;
}

struct buffer *buffer_init(size_t size)
{
	struct buffer *p = NULL;

	p = _malloc(sizeof(struct buffer));
	p->data = _malloc(size);
	p->lenght = size;

	return p;
}

void buffer_clean(struct buffer *p)
{
	if (!p)
		return;

	free(p->data);
	free(p);
}

