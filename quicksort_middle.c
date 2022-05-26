#include <stdio.h>

void swap(int *a, int *b);

void quick_sort_sub(int *data, int left, int right);

void quick_sort(int *data, int data_size);

int main(void) {
    int data[10] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    quick_sort(data, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\t", data[i]);
    }

    return 0;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort_sub(int *data, int left, int right) {
    int pivot = data[(left + right) / 2];
    int right_index = right;
    int left_index = left;

    while (left_index <= right_index) {
        for (; data[left_index] > pivot; left_index += 1);
        for (; data[right_index] < pivot; right_index -= 1);
        if (left_index <= right_index) {
            swap(&data[left_index], &data[right_index]);
            left_index += 1;
            right_index -= 1;
        }
    }
    if (right_index > left) quick_sort_sub(data, left, right_index);
    if (left_index < right) quick_sort_sub(data, left_index, right);
}

void quick_sort(int *data, int data_size) {
    quick_sort_sub(data, 0, data_size - 1);
}