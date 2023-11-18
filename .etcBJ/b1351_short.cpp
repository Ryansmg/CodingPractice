#include <stdio.h>
#include <map>
#define c long long
c n,p,q;std::map<c,c> m;c f(c a){if(a==0)return 1;auto r=m.find(a);if(r!=m.end())return r->second;c b=f(a/p)+f(a/q);m.insert({a,b});return b;}int main(){scanf("%lld %lld %lld",&n,&p,&q);printf("%lld",f(n));}