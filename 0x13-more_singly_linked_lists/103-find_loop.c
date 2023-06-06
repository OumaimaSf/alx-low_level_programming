#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * *find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The address of the node where the loop starts, NULL if there is no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *S, *F;

	if (head == NULL || head->next == NULL)
		return NULL;

	S = head->next;
	F = head->next->next;

	while (F && F->next)
	{
		if (S == F)
		{
			S = head;
			while (S != F)
			{
				S = S->next;
				F = F->next;
			}
			return (S);
		}
		S = S->next;
		F = F->next->next;
	}

	return NULL;
}
