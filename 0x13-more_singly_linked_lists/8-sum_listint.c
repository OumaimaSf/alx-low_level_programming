#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) of a listint_t linked list.
 * @head: Pointer to the head of list.
 *
 * Return: Sum of all the data (n) of the list.
 *         If the list is empty, returns 0.
 */
int sum_listint(listint_t *head)
{
	listint_t *C =head;
	int sum = 0;

	while (C != NULL)
	{
		sum += C->n;
		C = C->next;
	}
	return (sum);
}
