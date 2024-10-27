#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @array: The array
 * @a: The first element index
 * @b: The second element index
 */
void swap(int *array, size_t a, size_t b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
    print_array(array, b + 1); /* Print array after swap */
}

/**
 * sift_down - Sift down an element in the heap
 * @array: The array to heapify
 * @start: The starting index to sift down
 * @end: The end index of the heap
 */
void sift_down(int *array, size_t start, size_t end)
{
    size_t root = start;
    size_t child;

    while ((child = 2 * root + 1) <= end)
    {
        /* Choose the larger child */
        if (child + 1 <= end && array[child] < array[child + 1])
            child++;

        /* If root is less than the largest child, swap them */
        if (array[root] < array[child])
        {
            swap(array, root, child);
            root = child; /* Continue to sift down */
        }
        else
            return; /* If root is in the right place */
    }
}

/**
 * heapify - Build the heap from an array
 * @array: The array to be heapified
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
    size_t start;

    /* Start from the last parent node and sift down each node */
    for (start = (size - 2) / 2; start != (size_t)-1; start--)
        sift_down(array, start, size - 1);
}

/**
 * heap_sort - Sort an array of integers using the Heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (size < 2)
        return; /* Array is already sorted */

    /* Build the heap */
    heapify(array, size);

    /* One by one extract elements from heap */
    for (end = size - 1; end > 0; end--)
    {
        /* Move the current root to the end */
        swap(array, 0, end);
        /* Sift down the new root */
        sift_down(array, 0, end - 1);
    }
}
