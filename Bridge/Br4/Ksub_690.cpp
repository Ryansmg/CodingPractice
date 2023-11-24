#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

int main() {
    vector<ll> cnt(301,0);
    for(int i=1; i<250; i++)
        for(int j=i; j<250; j++) {
            auto sq = sqrt(i*i + j*j);
            if(i+j+sq>300) continue;
            if(sq == floor(sq)) {
                cnt[i+j+sq]++;
            }

        }

    vector<int> av;
    for(int i=1; i<300; i++)
        if(cnt[i]==1) {av.push_back(i);}

    int n;
    cin >> n;
    int i;
    for(i=0; av[i]<=n; i++) {}
    cout << i;
}