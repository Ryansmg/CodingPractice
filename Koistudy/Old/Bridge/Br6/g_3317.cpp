#include <iostream>
#include <vector>
#define L long long
int main(){using namespace std;L n,a,b,l=0,k=0,i,s,h,t;cin>>n;vector<L> v;for(i=0;i<n;i++){cin>>t;v.push_back(t);}cin>>a>>b;for(i=a-1;i<b;i++)l+=v[i];for(i=0;i<n;i++){s=0;h=i;while(h<n){s+=v[h++];if(s==l)k++;}}cout<<k;}