#include <stdio.h>

int main() 
{
    FILE *in, *out;
    int min=999, max=0, i, a[10];

    in = fopen("sample.txt", "r");
    out = fopen("print.txt", "w");

    for(i=0; i<10; i++)
        fscanf(in, "%d", &a[i]);

    for(i=0; i<10; i++)
    {
        if(a[i] < min)
            min = a[i];
         if(a[i] > max)
            max = a[i];
    }

    fprintf(out, "%d \n%d", min, max);

    fclose(in);
    fclose(out);
}