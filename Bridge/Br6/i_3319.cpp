#include <iostream>
#define L long long
bool a(L i){L p[]={2,3,5,7,11,13,17,19,23,29,31};for(L l:p)if(l==i)return 1;return 0;}int main(){L n,m=3,d=1,s=1,w=1,u=1;std::cin>>n;while(u<n){s++;d++;if(m==3&&d==32){m=4;d=1;}if(m==4&&d==31){m=5;d=1;}if(a(d)){w*=3;u+=w;}else{w*=2;u+=w;}}std::cout<<s;}