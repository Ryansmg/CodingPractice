#include <bits/stdc++.h>
using namespace std;

struct frac {
    int n=0, d=0; // 분자 / 분모
    frac()=default;
    frac(int a, int b) {
        n = a, d = b;
    }
    frac operator+(const frac &b) const {
        frac t;
        t.d = d*b.d;
        t.n = (n*b.d) + (b.n*d);
        return t;
    }
};

bool cmp(int a, int b) {
    return a > b;
}

void print() {
    cout << "asdf";
}

template <typename T>
void execute(T t) {
    t();
}

int main() {
    execute(print);
    frac* ptr = new frac();
    frac n(1, 3);
    delete ptr;
//    frac a, b, t;
//    cin >> a.n >> a.d >> b.n >> b.d;
//    t = a+b;
//    cout << t.n << ' ' << t.d;
//    int arr[] = { 5, 1, 5, 7 };
//    sort(arr, arr+4, cmp);
//
}
