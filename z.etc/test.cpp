#include <stdio.h>

int n, i, s, max=0, num=0;
int arr[100];

int main() {
    scanf("%d", &n);
    for(i=0; i<n*2; i++) {
        scanf("%d", &s);
        if(arr[s]==0) num++;
        else if(arr[s] == 1) num--;
        arr[s]++;
        if(max<num) max = num;
        printf("%d", num);
    }
}
