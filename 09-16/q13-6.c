#include <stdio.h>
#include <string.h>

int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    for(int i=0; i<3; i++){
        int arr[4], sum = 0;
        fscanf(in, "%d %d %d %d ", arr, arr+1, arr+2, arr+3);
        sum = arr[0] + arr[1] + arr[2] + arr[3];
        switch(sum){
            case 1:
                fprintf(out, "C\n");
                break;
            case 2:
                fprintf(out, "B\n");
                break;
            case 3:
                fprintf(out, "A\n");
                break;
            case 4:
                fprintf(out, "E\n");
                break;
            case 0:
                fprintf(out, "D\n");
                break;
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}