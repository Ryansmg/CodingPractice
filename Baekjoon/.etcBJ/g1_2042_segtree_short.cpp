#include <iostream>
#include <vector>
#define l long long
using namespace std;int main(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);l n,m,k;cin>>n>>m>>k;vector<l> t(4*n);for(l i=n;i<2*n;i++)cin>>t[i];for(l i=n-1;i>0;i--)t[i]=t[i<<1]+t[i<<1|1];for(l x=0;x<m+k;x++){l a,b,c;cin>>a>>b>>c;b--;if(a==1){t[n+b]=c;for(l i=n+b;i>1;i>>=1)t[i>>1]=t[i]+t[i^1];}else{l f=b+n,r=c+n,m=0;for(;f<r;f>>=1,r>>=1){if(f&1)m+=t[f++];if(r&1)m+=t[--r];}cout<<m<<"\n";}}}