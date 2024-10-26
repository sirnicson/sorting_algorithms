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
├── sort.h
├── 0-bubble_sort.c
├── 1-insertion_sort.c
├── 2-selection_sort.c
├── 3-quick_sort.c
├── 100-shell_sort.c
├── 101-cocktail_sort.c
├── 102-counting_sort.c
├── 103-merge_sort.c
├── 104-heap_sort.c
├── 105-radix_sort.c
├── 106-bitonic_sort.c
├── 107-quick_sort_hoare.c
├── 1000-sort_deck.c
├── deck.h
│
└── O/
    ├── 0-O              # Complexity for Bubble Sort
    ├── 1-O              # Complexity for Insertion Sort
    ├── 2-O              # Complexity for Selection Sort
    ├── 3-O              # Complexity for Quick Sort
    ├── 101-O            # Complexity for Cocktail Sort
    ├── 102-O            # Complexity for Counting Sort
    ├── 103-O            # Complexity for Merge Sort
    ├── 104-O            # Complexity for Heap Sort
    ├── 106-O            # Complexity for Bitonic Sort
    └── 107-O            # Complexity for Quick Sort Hoare
```

## Testing

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o sort && ./sort
```
