#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> arr, arr2;
void f(int i, int limit) {
    if(i>limit) return;
    arr2.push_back(arr[i] + arr[i+1]);
    if(i==limit) return;
    f(i+1, limit);
}
int calc(int height) {
    arr2.push_back(1);
    f(0, height-3);
    arr2.push_back(1);
    if(height == n) { return arr2[k-1]; }
    arr = arr2; arr2 = vector<int>();
    return calc(height+1);
}
int main() {
    cin >> n >> k;
    if(n<=2) { cout << 1; return 0; }
    cout << calc(2);
}

