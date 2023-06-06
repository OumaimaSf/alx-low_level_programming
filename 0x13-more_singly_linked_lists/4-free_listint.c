#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint - Frees a list
 * @head: Pointer to the head of the list.
 *
 */

void free_listint(listint_t *head)
{
	listint_t *T;

	while (head != NULL)
	{
		T = head;
		head = head->next;
		free(T);
	}
}
