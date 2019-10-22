#include "buffer.h"
#include "tools.h"

struct buffer *buffer_init(size_t size)
{
	struct buffer *p = NULL;

	p = _malloc(sizeof(struct buffer));
	if (!p)
		_system_panic();

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
