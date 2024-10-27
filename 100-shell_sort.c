#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              and the Knuth sequence.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t interval = 1, i, j;
    int temp;

    /* Generate the maximum interval following Knuth's sequence: n+1 = n * 3 + 1 */
    while (interval < size / 3)
        interval = interval * 3 + 1;

    /* Perform the Shell sort */
    while (interval >= 1)
    {
        for (i = interval; i < size; i++)
        {
            temp = array[i];
            j = i;
            while (j >= interval && array[j - interval] > temp)
            {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = temp;
        }

        /* Print the array after each interval reduction */
        print_array(array, size);

        /* Reduce the interval */
        interval = (interval - 1) / 3;
    }
}
