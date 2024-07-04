#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 整形数组，把偶数调整到数组的左边，奇数调整到数组的右边
void Reverse(int arr[], int size)
{
    int *left = arr;
    int *right = arr + size - 1;
    while (left < right)
    {
        while (left < right)
        {
            if ((*left & 0x1) == 1)
            {
                break;
            }
            left++;
        }

        while (left < right)
        {
            if ((*right & 0x1) == 0)
            {
                break;
            }
            right--;
        }

        if (left < right)
        {
            int tmp = *left;
            *left = *right;
            *right = tmp;
            right--;
            left++;
        }
    }
}

int main()
{
    int arr[10] = {0};
    srand(time(NULL));

    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 100;
    }

    for (auto v : arr)
    {
        cout << v << "  ";
    }
    cout << endl;

    Reverse(arr, sizeof(arr) / sizeof(int));

    for (auto v : arr)
    {
        cout << v << "  ";
    }
    cout << endl;

    return 0;
}