#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: double pointer to the head of the list.
 *
 * Return: The value stored in the head node's data (n).
 *         If the linked list is empty, returns O.
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *T;

	if (head == NULL || *head == NULL)
		return 0;

	T = *head;
	data = T->n;
	*head = (*head)->next;
	free(T);

	return data;
}
