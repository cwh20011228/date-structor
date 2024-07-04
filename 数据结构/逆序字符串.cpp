#include <iostream>
#include <string.h>
using namespace std;

void Reverse(char arr[],int size)
{
    char* left=arr;
    char* right = arr+size-1;
    while(left<right)
    {
        char tmp=*left;
        *left=*right;
        *right=tmp;
        left++;
        right--;
    }
}

int main()
{
    char arr[]="Hello world!";
    Reverse(arr,strlen(arr));
    cout<<arr<<endl;

    return 0;
}