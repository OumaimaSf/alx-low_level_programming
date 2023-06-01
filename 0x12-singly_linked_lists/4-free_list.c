#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * @head: A pointer to the head of the list.
 */
void free_list(list_t *head)
{
    list_t *crnt, *next_node;

    crnt = head;

    while (crnt != NULL) {
        next_node = crnt->next;
        free(crnt->str);
        free(crnt);
        crnt = next_node;
    }
}
