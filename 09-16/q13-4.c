#include <stdio.h>

int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    int n, k, count = 0, i;
    fscanf(in, "%d %d", &n, &k);
    for(i=1; i<=n; i++){
        if(n%i==0){
            count++;
            if(count == k){
                fprintf(out, "%d", i);
                fclose(in);
                fclose(out);
                return 0;
            }
        }
    }
    fprintf(out, "0");
    fclose(in);
    fclose(out);
    return 0;
}