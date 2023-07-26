#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2) {
	if (*list == NULL || node1 == NULL || node2 == NULL)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node2->prev == NULL)
		*list = node2;
}

void insertion_sort_list(listint_t **list) {
	listint_t *curr, *insertion_point;
	if (*list == NULL || (*list)->next == NULL) {
		return;
	}

	*curr = *list;

	while (curr != NULL) {
		*insertion_point = curr->prev;
		listint_t *prev_node = NULL;

		while (insertion_point && insertion_point->n > curr->n) {
			prev_node = insertion_point;
			insertion_point = insertion_point->prev;
		}

		if (insertion_point == NULL) {
			*list = curr;
		} else {
			prev_node->next = curr;
		}

		if (curr->next) {
			curr->next->prev = curr->prev;
		}

		curr->prev = prev_node;
		curr = curr->next;
	}
}


listint_t *create_node(int data) {
	listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
	if (new_node == NULL) {
		fprintf(stderr, "Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

void append_node(listint_t **list, listint_t *new_node) {
	if (*list == NULL) {
		*list = new_node;
	} else {
		listint_t *current = *list;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}
}

