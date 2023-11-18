#include <stdio.h>

int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int price, count, now;
    fscanf(in, "%d %d %d", &price, &count, &now);
    int answer = price*count - now;
    if(answer<0) fprintf(out, "0");
    else fprintf(out, "%d", answer);
    return 0;
}