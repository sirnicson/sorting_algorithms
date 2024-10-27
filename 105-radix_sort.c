#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort_for_radix - A function that sorts the array
 * @array: The array to be sorted
 * @size: The size of the array
 * @place: The place value (1, 10, 100, etc.)
 */
void counting_sort_for_radix(int *array, size_t size, int place)
{
    int *output; /* Output array that will hold the sorted array */
    int count[10] = {0}; /* Initialize count array to zero */
    size_t i;

    output = malloc(sizeof(int) * size); /* Allocate memory for output array */
    if (!output)
        return;

    /* Store the count of occurrences in count[] */
    for (i = 0; i < size; i++)
    {
        count[(array[i] / place) % 10]++;
    }

    /* Change count[i] so that it contains the actual position of
       this digit in output[] */
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    /* Build the output array */
    for (i = size; i > 0; i--)
    {
        output[count[(array[i - 1] / place) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / place) % 10]--;
    }

    /* Copy the output array to array[] */
    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    /* Free the output array */
    free(output);

    /* Print the array after sorting by this digit */
    print_array(array, size);
}

/**
 * get_max - A utility function to get the maximum value in array[]
 * @array: The array to be checked
 * @size: The size of the array
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * radix_sort - The main function that sorts the array using Radix sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max; /* Maximum number */
    size_t place;

    if (array == NULL || size < 2)
        return; /* Return if the array is NULL or has less than two elements */

    /* Get the maximum number to know the number of digits */
    max = get_max(array, size);

    /* Apply counting sort to sort elements based on place value */
    for (place = 1; max / place > 0; place *= 10)
    {
        counting_sort_for_radix(array, size, place);
    }
}
