#include <iostream>

using namespace std;

//int partition(int* arr_ptr, int arr_sz) {
//    // return pivot index;
//    if (arr_sz = 1) {
//        return 0;
//    }
//}

void sortWithInsertionSort(int* arr_ptr, int arr_sz) {
    int forward_index = 1;
    while (forward_index < arr_sz) {
        int reverse_index = forward_index;
        while (reverse_index > 0 && (*(arr_ptr + reverse_index - 1) > *(arr_ptr + reverse_index))) {
            int tmp = *(arr_ptr + reverse_index - 1);
            *(arr_ptr + reverse_index - 1) = *(arr_ptr + reverse_index);
            *(arr_ptr + forward_index) = tmp;

            --reverse_index;
        }

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
    int arr[] = { 3, 1, 2 };
    int arr_sz = sizeof(arr) / sizeof(int);
    sortWithInsertionSort(&arr[0], arr_sz);

    for (int i = 0; i < arr_sz; ++i) {
        cout << arr[i];
    }

    cout << endl;
    return 0;
}
