#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a list.
 * @head: Pointer to the head of th list.
 * @n: Value to be stored in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *N, *T;

	N = malloc(sizeof(listint_t));
	if (N == NULL)
		return NULL;

	N->n = n;
	N->next = NULL;

	if (*head == NULL)
	{
		*head = N;
	}
	else
	{
		T = *head;
		while (T->next != NULL)
			T = T->next;

		T->next = N;
	}
	return (N);
}
