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
void counting_sort(int *array, size_t size);
void merge(int *array, int *temp, size_t left, size_t middle, size_t right);
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right);
void merge_sort(int *array, size_t size);
void swap(int *array, size_t a, size_t b);
void sift_down(int *array, size_t start, size_t end);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
void counting_sort_for_radix(int *array, size_t size, int place);
int get_max(int *array, size_t size);
void radix_sort(int *array, size_t size);
void swap(int *array, size_t a, size_t b);
void bitonic_merge(int *array, size_t low, size_t cnt, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir);
void bitonic_sort(int *array, size_t size);

#endif /* SORT_H */
