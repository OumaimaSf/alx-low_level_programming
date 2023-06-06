#include <stdio.h>
#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of elements in the list.
 */

size_t listint_len(const listint_t *h)
{
	size_t A = 0;

	while (h != NULL)
	{
		A++;
		h = h->next;
	}

	return (A);
}
