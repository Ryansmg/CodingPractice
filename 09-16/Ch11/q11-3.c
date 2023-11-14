#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr_front = &arr[0], *ptr_back = &arr[9];

    while(ptr_back >= ptr_front){
        printf("%d ", *ptr_back);
        ptr_back--;
    }
}