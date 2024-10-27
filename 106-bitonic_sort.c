#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *array, size_t a, size_t b) {
    int temp;

    if (array[a] > array[b]) {
        temp = array[a];
        array[a] = array[b];
        array[b] = temp;

        /* Print the array after swapping */
        print_array(array, 1);
    }
}

void bitonic_merge(int *array, size_t low, size_t cnt, int dir) {
    if (cnt > 1) {
        size_t k = cnt / 2;
        size_t i;

        /* Print the merging process */
        printf("Merging [%lu/%lu] (%s):\n", (unsigned long)cnt, (unsigned long)cnt, dir ? "UP" : "DOWN");
        for (i = low; i < low + k; i++) {
            swap(array, i, i + k);
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir) {
    if (cnt > 1) {
        size_t k = cnt / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);

        printf("Merging [%lu/%lu] (%s):\n", (unsigned long)cnt, (unsigned long)cnt, dir ? "UP" : "DOWN");
        bitonic_merge(array, low, cnt, dir);
    }
}

void bitonic_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return; /* Return if the array is NULL or has less than two elements */

    print_array(array, size);
    bitonic_sort_recursive(array, 0, size, 1);
    printf("Result [%lu/%lu] (%s):\n", (unsigned long)size, (unsigned long)size, "UP");
    print_array(array, size);
}
