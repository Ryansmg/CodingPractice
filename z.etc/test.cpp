#include <bits/stdc++.h>
using namespace std;

template <typename T> T add(T a, T b) { return a + b; }

template <int a, int b> int add2 = a + b;

template <typename T1, typename T2>
void input(T1& a, T2& b) {
    cin >> a >> b;
}

int main() {
    cout << add<int>(1, 2);
    cout << add(3.5, 4.5);
    cout << add2<5, 6>;
}

