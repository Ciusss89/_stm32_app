#include "tools.h"

void *_malloc(size_t size)
{
	void *pt = malloc(size ? size : 1);
	if (pt == NULL)
		abort();
	return pt;
}
