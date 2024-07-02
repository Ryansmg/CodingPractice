#include <cstdio>
int main(){int a,b=70;scanf("%d",&a);b+=a<60?0:99-a>0?4-a/10:-5;printf("%c",b);}