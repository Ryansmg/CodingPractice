#import<bits/stdc++.h>
#define I int
I E(I i){std::cout<<i;exit(0);}I main(){I n,i=1;std::cin>>n;n--;for(;;i*=2){if(n-i>=0)n-=i;else break;if(n==1)E(i*2+1);if(!n)E(1);}E(i-n+1);}
