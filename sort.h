#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Data structure for a doubly linked list */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Prototypes for print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Prototypes for sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

#endif /* SORT_H */
