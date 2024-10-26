# 0x1B. C - Sorting Algorithms & Big O

This project implements various sorting algorithms in C, highlighting their efficiency with Big O notation.

## Overview

- **Goal**: Implement sorting algorithms and understand their time complexities.
- **Algorithms Covered**: Bubble Sort, Insertion Sort, Selection Sort, Quick Sort, and several advanced sorts.
- **Complexity Analysis**: Each algorithm includes best, average, and worst-case Big O notations.

## Requirements

- **Environment**: Ubuntu 20.04 LTS
- **Compiler**: `gcc` with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Code Style**: Betty style compliance
- **Files**: Max of 5 functions per file; no global variables allowed.

## Sorting Algorithms Implemented

1. **Bubble Sort**: `bubble_sort.c`
2. **Insertion Sort**: `insertion_sort_list.c`
3. **Selection Sort**: `selection_sort.c`
4. **Quick Sort**: `quick_sort.c`
5. **Advanced Algorithms**: Shell Sort, Cocktail Shaker Sort, Counting Sort, Merge Sort, Heap Sort, Radix Sort, Bitonic Sort, Quick Sort (Hoare Partition Scheme)

Each algorithm has a separate `.c` file and a corresponding complexity file (e.g., `0-O` for Bubble Sort) explaining the Big O notation.


## Project Structure

```plaintext
sorting_algorithms/
│
├── README.md
├── AUTHORS
│
├── bubble_sort.c
├── insertion_sort.c
├── selection_sort.c
├── quick_sort.c
├── shell_sort.c
├── cocktail_sort.c
├── counting_sort.c
├── merge_sort.c
├── heap_sort.c
├── radix_sort.c
├── bitonic_sort.c
│
└── O/
    ├── 0-O              # Complexity for Bubble Sort
    ├── 1-O              # Complexity for Insertion Sort
    ├── 2-O              # Complexity for Selection Sort
    ├── 3-O              # Complexity for Quick Sort
    ├── 4-O              # Complexity for Shell Sort
    ├── 5-O              # Complexity for Cocktail Sort
    ├── 6-O              # Complexity for Counting Sort
    ├── 7-O              # Complexity for Merge Sort
    ├── 8-O              # Complexity for Heap Sort
    ├── 9-O              # Complexity for Radix Sort
    └── 10-O             # Complexity for Bitonic Sort
```

## Testing

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o sort && ./sort
```
