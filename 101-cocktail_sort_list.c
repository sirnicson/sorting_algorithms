#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @left: Pointer to the first node to be swapped.
 * @right: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev)
        left->prev->next = right;
    else
        *list = right;
    
    if (right->next)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;
    left->prev = right;
    right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        current = *list;

        /* Traverse the list forward */
        while (current->next != NULL)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
            else
                current = current->next;
        }

        /* If no swaps occurred, list is sorted */
        if (!swapped)
            break;

        swapped = 0;
        current = current->prev;

        /* Traverse the list backward */
        while (current->prev != NULL)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
            }
            else
                current = current->prev;
        }
    } while (swapped);
}
