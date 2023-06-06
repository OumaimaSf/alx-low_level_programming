#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: Double pointer to the head of the list.
 *
 */

void free_listint2(listint_t **head)
{
	listint_t *T;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		T = *head;
		*head = (*head)->next;
		free(T);
	}
}
