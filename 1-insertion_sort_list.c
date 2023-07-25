#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s {
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2) {
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->prev)
        node2->prev->next = node1;

    listint_t *temp_prev = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp_prev;

    listint_t *temp_next = node1->next;
    node1->next = node2->next;
    node2->next = temp_next;

    if (!node1->prev)
        *list = node1;
    if (!node2->prev)
        *list = node2;
}

void insertion_sort_list(listint_t **list) {
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr = (*list)->next;

    while (curr) {
        listint_t *insertion_point = curr->prev;

        while (insertion_point && insertion_point->n > curr->n) {
            swap_nodes(list, insertion_point, curr);
            insertion_point = curr->prev;

            /*** Print the list after each swap ***/
            listint_t *temp = *list;
            while (temp) {
                printf("%d", temp->n);
                if (temp->next)
                    printf(", ");
                else
                    printf("\n");
                temp = temp->next;
            }
        }

        curr = curr->next;
    }
}

/*** Helper function to create a new node***/
listint_t *create_node(int n) {
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node) {
        new_node->n = n;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

/*** Helper function to add a node to the end of the linked list ***/
void add_node(listint_t **list, listint_t *new_node) {
    if (list == NULL || new_node == NULL)
        return;

    if (*list == NULL) {
        *list = new_node;
    } else {
        listint_t *temp = *list;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

/*** Helper function to print the linked list ***/
void print_list(listint_t *list) {
    while (list) {
        printf("%d", list->n);
        if (list->next)
            printf(", ");
        else
            printf("\n");
        list = list->next;
    }
}
