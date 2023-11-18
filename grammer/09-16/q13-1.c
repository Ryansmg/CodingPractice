#include <stdio.h>
int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int n[10], i, max, p;
    for(i=1;i<10;i++)
        fscanf(in, "%d", &n[i]);
    max=n[1];
    for(i=2; i<10; i++)
        if(n[i]>max)
        {
            max=n[i];
            p=i;
        }
    fprintf(out, "%d\n%d", max, p);
    fclose(in);
    fclose(out);
    return 0;
}