#include <stdio.h>
int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int n[7], i, sum = 0, min = 999;
    for(i=0;i<7;i++)
        fscanf(in, "%d", &n[i]);

    for(i=0;i<7;i++){
        if(n[i]%2 == 1){
            sum += n[i];
            if(min > n[i]) min = n[i];
        }
    }
    if(sum==0) fprintf(out, "-1");
    else fprintf(out, "%d\n%d", sum, min);
    fclose(in);
    fclose(out);
    return 0;
}