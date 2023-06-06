#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/** 
 * delete_nodeint_at_index - Deletes the node at index of a listint_t linked list.
 * @head: Double of pointer at the head of the list.
 * @index: Index of the node that should be deleted, starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node, *T;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current_node = *head;

	if (index == 0)
	{
		*head = current_node->next;
		free(current_node);
		return (1);
	}

	for (i = 0; i < index - 1 && current_node != NULL; i++)
	{
		current_node = current_node->next;
	}

	if (current_node == NULL || current_node->next == NULL)
		return (-1);

	T = current_node->next;
	current_node->next = T->next;
	free(T);

	return (1);
}
