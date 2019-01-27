#include <stdio.h>

/***** Some logging code for debugging *****/

const static int tab_stop = 4;

int indent_level = 0;

#define log(expr)                           \
    printf("%*s"     , indent_level, "");   \
    printf("%s: %d\n", #expr, expr)

#define logArray(arr_ptr, arr_sz)           \
    printf("{");                            \
    for (int i = 0; i < arr_sz; ++i) {      \
        if (i == arr_sz - 1) {              \
            printf("%d",   *(arr_ptr + i)); \
        } else {                            \
            printf("%d, ", *(arr_ptr + i)); \
        }                                   \
    }                                       \
    printf("}")

#define logArrayExpr(expr, arr_ptr, arr_sz) \
    printf("%*s",  indent_level, "");       \
    printf("%s: ", #expr);                  \
    logArray(arr_ptr, arr_sz);              \
    printf("\n")

#define logArrayArg(arr_ptr, arr_sz)        \
    logArray(arr_ptr, arr_sz)

#define logFun(arr_ptr, arr_sz)             \
    printf("%*s", indent_level, "");        \
    indent_level = indent_level + tab_stop; \
    printf("%s(", __FUNCTION__);            \
    logArrayArg(arr_ptr, arr_sz);           \
    printf(") {\n")

#define endLogFun()                         \
    indent_level = indent_level - tab_stop; \
    printf("%*s", indent_level, "");        \
    printf("}\n")

/*******************************************/

int partition(int* arr_ptr, int arr_sz) {
    logFun(arr_ptr, arr_sz);

    if (arr_sz <= 1) {
        return 0;
    }

    int pivot_index      = 0;
    int pivot_value      = *(arr_ptr + pivot_index);
    int index_to_compare = arr_sz - 1;
    int num_comparisons  = 0;
    while (++num_comparisons < arr_sz) {
        int value_to_compare = *(arr_ptr + index_to_compare);
        if (pivot_value > value_to_compare) {
            *(arr_ptr + pivot_index)      = value_to_compare;
            *(arr_ptr + index_to_compare) = *(arr_ptr + pivot_index + 1);
            *(arr_ptr + pivot_index + 1)  = pivot_value;

            ++pivot_index;
        } else {
            --index_to_compare;
        }

    }

    endLogFun();

    return pivot_index;
}

void sortWithInsertionSort(int* arr_ptr, int arr_sz) {
    logFun(arr_ptr, arr_sz);

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

    endLogFun();
}

void sortWithQuickSort(int* arr_ptr, int arr_sz) {
    logFun(arr_ptr, arr_sz);

    if (arr_sz <= 1) {
        return;
    }

    int pivot_index = partition(arr_ptr, arr_sz);
    log(pivot_index);

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

    endLogFun();
}

void sort(int* arr_ptr, int arr_sz) {
    logFun(arr_ptr, arr_sz);

    if (arr_sz > 10) {
        sortWithQuickSort(arr_ptr, arr_sz);
    } else {
        sortWithInsertionSort(arr_ptr, arr_sz);
    }

    endLogFun();
}

int main() {
    int arr[]  = { 25, 102, 953, 705, 284, 999, -1, 57, 492, 33, 15, 11, 148, 998, 775 };
    int arr_sz = sizeof(arr) / sizeof(int);

    sort(&arr[0], arr_sz);

    logArrayExpr(arr, &arr[0], arr_sz);

    return 0;
}
