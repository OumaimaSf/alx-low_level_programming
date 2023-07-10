#include <stdio.h>
#include "lists.h"

/*
 * print_list - Prints all the elements of a list_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes.
 */

size_t print_list(const list_t *h)
{
	const list_t *crnt = h;
	size_t cnt = 0;

	while (crnt != NULL)
	{
		if (crnt->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", crnt->len, crnt->str);

		cnt++;
		crnt = crnt->next;
	}
	return (cnt);
}
