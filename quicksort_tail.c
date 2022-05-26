//
// Created by 30456 on 2022/5/21.
//
#include <stdio.h>

void Swap(int *a, int *b);

void quick_sort_sub_tail(int *data, int left, int right);

void quick_sort_tail(int *data, int length);

int main(void) {
    int array[10] = {5, 3, 7, 5, 10, 2, 4, 15, 20, -9};
    quick_sort_tail(array, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\t", array[i]);
    }

    return 0;
}

void Swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort_sub_tail(int *data, int left, int right) {
    int left_index = left;
    int right_index = right - 1;
    int pivot = data[right];
    while (left_index <= right_index) {
        for (; data[left_index] > pivot; left_index += 1);
        for (; data[right_index] < pivot; right_index -= 1);
        if (left_index <= right_index) {
            Swap(&data[left_index], &data[right_index]);
            right_index -= 1;
            left_index += 1;
        }
    }
    if (left_index > right_index) {
        Swap(&data[left_index], &data[right]);
    }
    if (left < right_index) quick_sort_sub_tail(data, left, right_index);
    if (left_index < right) quick_sort_sub_tail(data, left_index, right);
}

void quick_sort_tail(int *data, int length) {
    quick_sort_sub_tail(data, 0, length - 1);
}