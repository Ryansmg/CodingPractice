#include <bits/stdc++.h>

using namespace std;
vector<int> A;
int main() {
    int n;
    int sum = 0;
    cin >> n;
    A.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    cout << sum;
}
