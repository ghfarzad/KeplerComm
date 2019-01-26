#include <iostream>

using namespace std;

void print(const string& name, int value) {
    cout << name << ": " << value << endl;
}

#define log(expr) print(#expr, expr)

int partition(int* arr_ptr, int arr_sz) {
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

//void sortWithQuckSort(int* arr_ptr, int arr_sz) {
//    if (arr_sz == 1) {
//        return;
//    }
//
//    int pivot_index = partition(arr_ptr, arr_sz);
//
//    int right_partition_sz = pivot_index;
//    int left_partition_sz  = arr_sz - right_partition_sz - 1;
//
//    if (right_partition_sz > 1) {
//        sortWithQuickSort(arr_ptr, right_partition_sz);
//    }
//
//    if (left_partion_sz){
//        sortWithQuickSort(arr_ptr + right_partition_sz, left_partition_sz);
//    }
//}

//void sort(int* arr_ptr, int arr_sz) {
//    if (arr_sz < 10) {
//        sortWithInsertionSort(arr_ptr, arr_sz);
//    } else {
//        sortWithQuckSort(arr_ptr, arr_sz);
//    }
//}

int main() {
    int arr[] = { 3, 1 , 2, 9, 3, 4, 8, 5, 6 };
    int arr_sz = sizeof(arr) / sizeof(int);

    int pivot_index = partition(&arr[0], arr_sz);
    int pivot_value = *(&arr[0] + pivot_index);
    log(pivot_index);
    log(pivot_value);
    //log(arr_sz);

    //sortWithInsertionSort(&arr[0], arr_sz);

    //for (int i = 0; i < arr_sz; ++i) {
    //    cout << arr[i];
    //}

    //cout << endl;
    return 0;
}
