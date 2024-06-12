#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr, arr2;
void f(int i, int limit) {
    if(i>limit) return;
    arr2.push_back(arr[i] + arr[i+1]);
    if(i==limit) return;
    f(i+1, limit);
}
void f2(int i, int limit) {
    if(i>limit) return;
    cout << arr2[i] << ' ';
    if(i==limit) return;
    f2(i+1, limit);
}
void calc(int height) {
    arr2.push_back(1);
    f(0, height-3);
    arr2.push_back(1);
    f2(0, height-1);
    cout << '\n';
    if(height == n) { return; }
    arr = arr2; arr2 = vector<int>();
    calc(height+1);
}
int main() {
    cin >> n;
    if(n==1) { cout << 1; return 0; }
    if(n==2) { cout << "1\n1 1"; return 0; }
    cout << "1\n";
    calc(2);
}

