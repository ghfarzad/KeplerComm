# KeplerComm

To build and run:
1. `gcc main.c -o main`
2. `./main`

Sample ouput:
```
sort(arr: {25, 102, 953, 705, 284, 999, -1, 57, 492, 33, 15, 11, 148, 998, 775, 10, 15, 8989, 124, 145}, arr_sz: 20) {
    sortWithQuickSort(arr: {25, 102, 953, 705, 284, 999, -1, 57, 492, 33, 15, 11, 148, 998, 775, 10, 15, 8989, 124, 145}, arr_sz: 20) {
        partition(arr: {25, 102, 953, 705, 284, 999, -1, 57, 492, 33, 15, 11, 148, 998, 775, 10, 15, 8989, 124, 145}, arr_sz: 20) {
        }
        pivot_index: 6
        sortWithQuickSort(arr: {57, 492, 999, 284, 705, 148, 998, 775, 953, 102, 8989, 124, 145}, arr_sz: 13) {
            partition(arr: {57, 492, 999, 284, 705, 148, 998, 775, 953, 102, 8989, 124, 145}, arr_sz: 13) {
            }
            pivot_index: 10
            sortWithInsertionSort(arr: {8989, 999}, arr_sz: 2) {
            }
            sortWithInsertionSort(arr: {145, 492, 124, 284, 705, 148, 57, 775, 953, 102}, arr_sz: 10) {
            }
        }
        sortWithInsertionSort(arr: {15, 10, 11, 15, 25, -1}, arr_sz: 6) {
        }
    }
}
arr: {-1, 10, 11, 15, 15, 25, 33, 57, 102, 124, 145, 148, 284, 492, 705, 775, 953, 998, 999, 8989}

```
