#include <bits/stdc++.h>
int p(int a) {
	printf("%d ", a);
	return a&1;
}

int main() {
	if(p(2) || p(6) || p(3) || p(8)) printf("a\n");
	if(p(3) && p(2) && p(4)) printf("b");
}
