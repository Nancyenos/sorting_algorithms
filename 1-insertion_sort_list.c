#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm
 *
 * @list: Double pointer to the first element of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr)
	{
		listint_t *key = curr;
		listint_t *prev = curr->prev;

		while (prev && prev->n > key->n)
		{
			/* Perform the swap of nodes */
			listint_t *tmp_prev = prev->prev;
			listint_t *tmp_next = key->next;

			if (tmp_prev)
				tmp_prev->next = key;
			else
				*list = key;

			if (tmp_next)
				tmp_next->prev = prev;

			key->prev = tmp_prev;
			key->next = prev;
			prev->prev = key;
			prev->next = tmp_next;

			print_list(*list);

			prev = key->prev;
		}

		curr = curr->next;
	}
}
