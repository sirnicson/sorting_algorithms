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

## Testing

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o sort

./sort
```
