#include <stdio.h>

int main() {
    int tar, in, size = 0, arr[100];
    scanf("%d %d", &tar, &in);
    while(tar) {
        int out = tar % in;
        arr[size++] = (out<=9) ? '0'+out : 'a'+out-10;
        tar /= in;
    }
    while(size--) printf("%c", arr[size]);
}