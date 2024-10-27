#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of array[].
 *         The first subarray is array[l..m]
 *         The second subarray is array[m+1..r]
 * @array: The main array to sort
 * @temp: Temporary array used for merging
 * @left: The starting index of the first subarray
 * @middle: The ending index of the first subarray
 * @right: The ending index of the second subarray
 */
void merge(int *array, int *temp, size_t left, size_t middle, size_t right)
{
    size_t i, j, k;

    i = left;
    j = middle;
    k = left;

    printf("Merging...\n[left]: ");
    print_array(array + left, middle - left);
    printf("[right]: ");
    print_array(array + middle, right - middle);

    while (i < middle && j < right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i < middle)
        temp[k++] = array[i++];
    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively divides and sorts the array
 * @array: The array to sort
 * @temp: Temporary array for merging
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    size_t middle;

    if (right - left <= 1)
        return;

    middle = left + (right - left) / 2;

    merge_sort_recursive(array, temp, left, middle);
    merge_sort_recursive(array, temp, middle, right);
    merge(array, temp, left, middle, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the top-down Merge sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, 0, size);

    free(temp);
}
