#include <stdio.h>

void sort(int* arr)
{
    int count=0, i, j, temp;
    while(arr[count] == 0) count++;

    for(i=0; i<count-1; i++){
        for(j=0; j<count-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int arrSize(int* arr)
{
    int count=0;
    while(arr[count] == 0) count++;
    return count;
}

int main()
{
    int arr[100] = {0};
    int arr2[10] = {15, 20, 31, 50, 66, 72, 78, 81, 96, 99};
    for(int i=0; i<10; i++) arr[i] = arr2[i];

    int i;
    while(1)
    {
        sort(arr);
        int size = arrSize(arr);
        char c; int input;
        for(i=0; i<size; i++) printf("%d ", arr[i]);
        printf("\nHow ? ");
        scanf(" %c, %d", &c, &input);

        switch(c)
        {
            case 'c':
            case 'C':
                for(i=0; i<size; i++) { if(arr[i] == input) break; }
                for(int j=i; j<size-1; j++) arr[j] = arr[j+1];
        }
    }
}