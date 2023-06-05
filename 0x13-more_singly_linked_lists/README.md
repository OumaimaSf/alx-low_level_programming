# C - More singly linked lists

## General
* How to use linked lists
* Start to look for the right source of information without too much help

### Please use this data structure for this project:

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

## Tasks
0. Print list
Write a function that prints all the elements of a listint_t list.
1. List length
Write a function that returns the number of elements in a linked listint_t list.
2. Add node
Write a function that adds a new node at the beginning of a listint_t list.
3. Add node at the end
Write a function that adds a new node at the end of a listint_t list.
4. Free list
Write a function that frees a listint_t list.
5. Free
Write a function that frees a listint_t list.
6. Pop
Write a function that deletes the head node of a listint_t linked list, and returns the head node’s data (n).
7. Get node at index
Write a function that returns the nth node of a listint_t linked list.
8. Sum list
Write a function that returns the sum of all the data (n) of a listint_t linked list.
9. Insert
Write a function that inserts a new node at a given position.
10. Delete at index
Write a function that deletes the node at index index of a listint_t linked list.
