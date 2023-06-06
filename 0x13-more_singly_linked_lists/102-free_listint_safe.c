#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: Size of the list that was free'd.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *C, *T;
	size_t count = 0;

	if (h == NULL)
		return 0;

	C = *h;

	while (C != NULL)
	{
		T = C->next;
		free(C);
		C = T;
		count++;
	}

	*h = NULL;

	return (count);
}
