#include <stdio.h>

int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int arr[5], i, j, avg = 0;
    for(i=0; i<5; i++){
        fscanf(in, "%d", &arr[i]);
        avg += arr[i];
    }
    avg = avg / 5;

    for(i=0; i<4; i++) {
        for(j=i+1; j<5; j++){
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    fprintf(out, "%d\n%d", avg, arr[2]);
}