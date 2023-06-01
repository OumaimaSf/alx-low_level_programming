#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Returns the number of elements in a linked list_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes.
 */
size_t list_len(const list_t *h)
{
    const list_t *crnt = h;
    size_t cnt = 0;

    while (crnt != NULL)
    {
        cnt++;
        crnt = crnt->next;
    }

    return (cnt);
}
