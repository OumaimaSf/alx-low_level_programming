#include <stdlib.h>
#include "main.h"

void *malloc_checked(unsigned it b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}

	return ptr;
}
