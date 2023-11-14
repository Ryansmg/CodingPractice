#include <stdio.h>

int main()
{
    int n[5];
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    fscanf(in, "%d %d %d %d %d", n, n+1, n+2, n+3, n+4);

    int answer = 0;
    for(int i=0; i<5; i++)
        answer += n[i]*n[i];
    fprintf(out, "%d", answer%10);

    fclose(in);
    fclose(out);

    return 0;
}