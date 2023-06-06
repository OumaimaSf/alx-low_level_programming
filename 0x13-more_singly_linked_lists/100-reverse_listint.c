#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Double pointer to the head of the list.
 *
 * Return: Pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *P = NULL;
	listint_t *N = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);

	while (*head != NULL)
	{
		N = (*head)->next;
		(*head)->next = P;
		P  = *head;
		*head = N;
	}

	*head = P;

	return *head;
}
