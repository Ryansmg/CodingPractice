#include <bits/stdc++.h>
using namespace std;

struct cow {
    int n, a, b;
    cow()=default;
    cow(int c, int d, int e) : n(c), a(d), b(e) {}
    bool operator<(const cow& other) {
        return a > other.a;
    }
    int operator,(int i) const {
        return n + i;
    }
};
bool cmp(const cow& a, const cow& b) {
    return a.b > b.b;
}

int main() {
    int n, k; cin >> n >> k;
    vector<cow> arr;
    for(int i=0; i<n; i++) {
        int b, c; cin >> b >> c;
        arr.emplace_back(i+1, b, c);
    }
    sort(arr.begin(), arr.end());
    sort(arr.begin(), arr.begin()+k, cmp);
    cout << (arr[0], 1);
}
