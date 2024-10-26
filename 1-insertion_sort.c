#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion Sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *swap;	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		swap = current;
		while (swap->prev != NULL && swap->n < swap->prev->n)
        {
		tmp = swap->prev;
		tmp->next = swap->next;
		if (swap->next != NULL)
			swap->next->prev = tmp;
		swap->prev = tmp->prev;
		swap->next = tmp;
		tmp->prev = swap;
		if (swap->prev != NULL)
			swap->prev->next = swap;
		else
			*list = swap;
		print_list(*list);
	}
		current = current->next;
	}
}
