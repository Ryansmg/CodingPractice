#include <cstdio>
#include <cstdlib>
#include <random>
#include <bits/stdc++.h>
using namespace std;

static int n,a[1555];
static int total_queries=0,result;

int query(int i,int v){
    if(i<0||i>=n||v<0||v>=n){
        printf("-1"); exit(0);
    }
    total_queries++;
    return (a[i]<=v);
}

int get_maximum(int n){
    int ans = 0;
    vector<int> s; for(int i=0; i<n; i++) s.emplace_back(i);
    shuffle(s.begin(), s.end(), mt19937(random_device()()));
    for(int i : s) {
        int cans = 0;
        for(int l = ans, r = n-1; l<=r;) {
            if(query(i, (l+r)/2)) r = (l+r)/2-1;
            else cans = max(cans, (l+r)/2+1), l = (l+r)/2+1;
        }
        ans = max(ans, cans);
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    result=get_maximum(n);
    printf("%d\n%d\n",result,total_queries);
}

// 3 1 4 1 0