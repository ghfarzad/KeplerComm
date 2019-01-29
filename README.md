# KeplerComm

To build and run:
1. `gcc main.c -o main`
2. `./main`

Sample ouput:
```
sort(arr: {25, 102, 953, 705, 284, 999, -1, 57, 492, 33, 15, 11, 148, 998, 775}, arr_sz: 15) {
    sortWithQuickSort(arr: {25, 102, 953, 705, 284, 999, -1, 57, 492, 33, 15, 11, 148, 998, 775}, arr_sz: 15) {
        partition(arr: {25, 102, 953, 705, 284, 999, -1, 57, 492, 33, 15, 11, 148, 998, 775}, arr_sz: 15) {
        }
        pivot_index: 5
        sortWithInsertionSort(arr: {999, 284, 492, 705, 953, 102, 148, 998, 775}, arr_sz: 9) {
        }
        sortWithInsertionSort(arr: {11, 15, 33, 25, -1}, arr_sz: 5) {
        }
    }
}
arr: {-1, 11, 15, 25, 33, 57, 102, 148, 284, 492, 705, 775, 953, 998, 999}
```
