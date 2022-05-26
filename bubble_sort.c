//
// 冒泡排序法
//
#include <stdio.h>
#include <stdbool.h>

void bubble_sort_increase_first(int *data, int length);

void bubble_sort_increase_second(int *data, int length);

void swap(int *a, int *b);

int main(void) {
    int num[10] = {20, 7, -1, 6, 25, 12, 15, 3, -7, 14};
    //bubble_sort_increase_first(num, 10);
    bubble_sort_increase_second(num,10);
    for (int i = 0; i < 10; i++) {
        printf("%d\t", num[i]);
    }

    return 0;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort_increase_first(int *data, int length) {
    for (int i = 0; i < length - 1; i++) {
        bool is_sorted_tag = true;
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                is_sorted_tag = false;
                swap(&data[j], &data[j + 1]);
            }
        }
        if (is_sorted_tag) break;
    }
}

void bubble_sort_increase_second(int *data, int length) {
    int lastExchangeIndex = 0; // 记录最后依次交换的位置
    int sortBorder = length - 1; // 记录无序数列的边界，每次比较只需要比到这里为止
    for (int i = 0; i < length - 1; i++) {
        bool is_sorted_tag = true; // 有序标记，每一轮的初始是true
        for (int j = 0; j < sortBorder; j++) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
                is_sorted_tag = false;  // 如果交换，is_sorted_tag = false;
                lastExchangeIndex = j;
            }
        }
        sortBorder = lastExchangeIndex;
        if (is_sorted_tag) break;
    }
}
