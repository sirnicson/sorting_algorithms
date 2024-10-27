#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*
 * swap - Swap two elements in an array.
 * @array: The array where the swap will occur.
 * @a: The index of the first element.
 * @b: The index of the second element.
 */
void swap(int *array, size_t a, size_t b)
{
    int temp;

    if (array[a] != array[b]) /* Only swap if they are different */
    {
        temp = array[a];
        array[a] = array[b];
        array[b] = temp;

        /* Print the array after the swap */
        print_array(array, 10); /* Adjust the number to the size of the array as needed */
    }
}

/*
 * hoare_partition - Partition the array using the Hoare scheme.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The final index of the pivot.
 */
int hoare_partition(int *array, size_t low, size_t high)
{
    int pivot = array[high]; /* Choose the last element as the pivot */
    size_t i = low - 1;      /* Start i just before low */
    size_t j = high + 1;     /* Start j just after high */

    while (1)
    {
        /* Increment j until we find an element <= pivot */
        do {
            j--;
        } while (array[j] > pivot && j > low);

        /* Increment i until we find an element >= pivot */
        do {
            i++;
        } while (array[i] < pivot && i < high);

        if (i < j) /* If the indices have not crossed, swap */
        {
            swap(array, i, j);
        }
        else
        {
            return j; /* Return the index of the pivot */
        }
    }
}

/*
 * quick_sort_recursive - Recursive function for Quick Sort.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 */
void quick_sort_recursive(int *array, size_t low, size_t high)
{
    if (low < high) /* Ensure valid partition */
    {
        int pivot_index = hoare_partition(array, low, high); /* Partition the array */
        quick_sort_recursive(array, low, pivot_index); /* Sort left partition */
        quick_sort_recursive(array, pivot_index + 1, high); /* Sort right partition */
    }
}

/*
 * quick_sort_hoare - Main function to perform Quick Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2) /* Handle invalid inputs */
        return;

    quick_sort_recursive(array, 0, size - 1); /* Start the sorting process */
}
