#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    int max = 0;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Allocate memory for the count and output arrays */
    count = malloc(sizeof(int) * (max + 1));
    output = malloc(sizeof(int) * size);
    if (!count || !output)
    {
        free(count);
        free(output);
        return;
    }

    /* Initialize count array to 0 */
    for (i = 0; i <= (size_t)max; i++)
        count[i] = 0;

    /* Store the count of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Update count array to store cumulative counts */
    for (i = 1; i <= (size_t)max; i++)
        count[i] += count[i - 1];

    /* Print the counting array */
    print_array(count, max + 1);

    /* Build the output array */
    for (i = size; i > 0; i--)
    {
        output[count[array[i - 1]] - 1] = array[i - 1];
        count[array[i - 1]]--;
    }

    /* Copy sorted elements back to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free allocated memory */
    free(count);
    free(output);
}
