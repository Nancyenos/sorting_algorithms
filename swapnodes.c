#include <stdlib.h>
#include "sort.h"
/**
 * swap_nodes - swaps the nodes
 * @list: pointer to pointer list
 * @node1: receives a node
 * @node2: recieves another node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp_prev = node1->prev;
	listint_t *temp_next = node1->next;

	if (node1->prev)
		node1->prev->next = node2;
	if (node2->prev)
		node2->prev->next = node1;

	node1->prev = node2->prev;
	node1->next = node2->next;
	node2->prev = temp_prev;
	node2->next = temp_next;

	if (!node1->prev)
		*list = node1;
	if (!node2->prev)
		*list = node2;
}
