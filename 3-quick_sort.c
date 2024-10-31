#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_quick(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - Partitions the array using the Lomuto partition scheme.
 * @array: The array to partition.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: The size of the array (for printing).
 * Return: The final partition index.
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                swap_quick(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != high)
    {
        swap_quick(&array[i], &array[high]);
        print_array(array, size);
    }
    return (i);
}

/**
 * quicksort - Recursive function to implement Quick Sort.
 * @array: The array to sort.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = partition(array, low, high, size);
        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}
