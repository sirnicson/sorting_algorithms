#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *array, size_t a, size_t b)
{
    int temp;

    if (array[a] != array[b]) /* Only swap if they are different */
    {
        temp = array[a];
        array[a] = array[b];
        array[b] = temp;
        print_array(array, 10); /* Adjust the size as needed */
    }
}

int hoare_partition(int *array, size_t low, size_t high)
{
    int pivot = array[low]; /* Choose the first element as the pivot */
    size_t i = low;         /* Start i at low */
    size_t j = high;        /* Start j at high */

    while (1)
    {
        while (array[j] > pivot) /* Decrement j until we find an element <= pivot */
            j--;

        while (array[i] < pivot) /* Increment i until we find an element >= pivot */
            i++;

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

void quick_sort_recursive(int *array, size_t low, size_t high)
{
    if (low < high) /* Ensure valid partition */
    {
        int pivot_index = hoare_partition(array, low, high); /* Partition the array */
        quick_sort_recursive(array, low, pivot_index);       /* Sort left partition */
        quick_sort_recursive(array, pivot_index + 1, high); /* Sort right partition */
    }
}

void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2) /* Handle invalid inputs */
        return;

    quick_sort_recursive(array, 0, size - 1); /* Start the sorting process */
}
