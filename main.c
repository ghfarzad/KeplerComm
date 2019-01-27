#include <stdio.h>

#define log(expr) printf("%s: %d\n", #expr, expr)
#define logFun()  printf("%s()\n", __FUNCTION__)

int partition(int* arr_ptr, int arr_sz) {
    logFun();

    if (arr_sz <= 1) {
        return 0;
    }

    int pivot_index      = 0;
    int pivot_value      = *(arr_ptr + pivot_index);
    int index_to_compare = arr_sz - 1;
    int num_comparisons  = 0;
    while (++num_comparisons < arr_sz) {
        log(num_comparisons);
        log(index_to_compare);

        int value_to_compare = *(arr_ptr + index_to_compare);
        log(value_to_compare);
        if (pivot_value > value_to_compare) {
            *(arr_ptr + pivot_index)      = value_to_compare;
            *(arr_ptr + index_to_compare) = *(arr_ptr + pivot_index + 1);
            *(arr_ptr + pivot_index + 1)  = pivot_value;

            ++pivot_index;
        } else {
            --index_to_compare;
        }

        log(pivot_index);
    }

    return pivot_index;
}

void sortWithInsertionSort(int* arr_ptr, int arr_sz) {
    logFun();

    if (arr_sz <= 1) {
        return;
    }

    int forward_index = 1;
    while (forward_index < arr_sz) {
        int sort_candidate = *(arr_ptr + forward_index);
        int reverse_index  = forward_index - 1;
        while (reverse_index >= 0 && (*(arr_ptr + reverse_index) > sort_candidate)) {
            *(arr_ptr + reverse_index + 1) = *(arr_ptr + reverse_index);
            --reverse_index;
        }

        *(arr_ptr + reverse_index + 1) = sort_candidate;
        ++forward_index;
    }
}

void sortWithQuickSort(int* arr_ptr, int arr_sz) {
    logFun();

    if (arr_sz <= 1) {
        return;
    }

    int pivot_index = partition(arr_ptr, arr_sz);

    int left_partition_sz  = pivot_index;
    int right_partition_sz = arr_sz - left_partition_sz - 1;

    if (right_partition_sz > 10) {
        sortWithQuickSort(arr_ptr + pivot_index + 1, right_partition_sz);
    } else {
        sortWithInsertionSort(arr_ptr + pivot_index + 1, right_partition_sz);
    }

    if (left_partition_sz > 10) {
        sortWithQuickSort(arr_ptr, left_partition_sz);
    } else {
        sortWithInsertionSort(arr_ptr, left_partition_sz);
    }
}

void sort(int* arr_ptr, int arr_sz) {
    logFun();

    log(arr_sz);

    if (arr_sz > 10) {
        sortWithQuickSort(arr_ptr, arr_sz);
    } else {
        sortWithInsertionSort(arr_ptr, arr_sz);
    }
}

int main() {
    int arr[]  = { 25, 102, 953, 705, 284, 999, -1, 57, 492, 33, 15, 11, 148, 998, 775 };
    int arr_sz = sizeof(arr) / sizeof(int);

    //int pivot_index = partition(&arr[0], arr_sz);
    //int pivot_value = *(&arr[0] + pivot_index);
    //log(pivot_index);
    //log(pivot_value);

    sort(&arr[0], arr_sz);

    for (int i = 0; i < arr_sz; ++i) {
        if (i == arr_sz - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d-", arr[i]);
        }
    }

    printf("\n");

    return 0;
}
