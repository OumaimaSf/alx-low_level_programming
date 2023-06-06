#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head list.
 * @index: Index of the node, strating at 0.
 *
 * Return: Pointer to the nth node.
 *         If the node does not exist, returns NULL.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *C = head;
	unsigned int A = 0;

	while (C != NULL)
	{
		if (A == index)
			return (C);
		A++;
		C = C->next;
	}
	return NULL;
}
