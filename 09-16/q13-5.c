#include <stdio.h>
#include <string.h>

int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    int count, i;
    int x, y;
    char c;
    fscanf(in, "%d", &count);

    for(i=0; i<count; i++)
    {
        fscanf(in, " %d %c %d", &x, &c, &y);
        switch(c){
            case '+':
                fprintf(out, "%d\n", x + y);
                break;
            case '-':
                fprintf(out, "%d\n", x-y);
                break;
            case '*':
                fprintf(out, "%d\n", x*y);
                break;
            case '/':
                fprintf(out, "%d\n", x/y);
                break;
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}