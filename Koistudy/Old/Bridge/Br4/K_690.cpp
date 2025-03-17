#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

int main() {
    vector<ll> cnt(10000,0);
    for(int i=1; i<250; i++)
        for(int j=i; j<250; j++) {
            for(int k=j; k<250; k++)
                if(i*i + j*j == k*k) cnt[i+j+k]++;

        }

    vector<int> av;
    for(int i=1; i<=600; i++)
        if(cnt[i]==1) {av.push_back(i);}

    int n;
    cin >> n;
    int i;
    for(i=0; av[i]<=n; i++) {}
    cout << i;
}