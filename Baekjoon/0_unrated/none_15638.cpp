#include<iostream>
main(){int n,i=2;std::cin>>n;bool p=1;for(;i*i<=n;)if(n%i++==0){p=0;break;}std::cout<<(p?"Yes":"No");}