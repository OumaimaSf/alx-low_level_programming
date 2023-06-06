#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Number of nodes in the list
 *         If it fails, exit with status 98
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *S, *F;
	size_t count = 0;

	S = F = head;

	while (S && F && F->next)
	{
		printf("[%p] %d\n", (void *)S, S->n);
		count++;

		S = S->next;
		F = F->next->next;

		if (S == F)
		{
			printf("-> [%p] %d\n", (void *)S, S->n);
			break;
		}
	}
	return (count);
}
