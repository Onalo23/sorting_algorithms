#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @h: Pointer head of a doubly linked list
 * @n1: the first node to be swapped
 * @n2: the second node to be swapped
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;

	else
		*h = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts doubly linked list of an ints
 *			with the aid of insertion sort algorithms
 * @list: Pointer to head of doubly linked list of an ints
 * discription: prints list after is been swapped
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *path, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (path = (*list)->next; path != NULL; path = tmp)
	{
		tmp = path->next;
		insert = path->prev;

		while (insert != NULL && path->n < insert->n)
		{
			swap_nodes(list, &insert, path);
			print_list((const listint_t *)*list);
		}
	}
}
