#include <iostream>
#include <random>
using namespace std;

bool isAvailable(int i) {
    //int exclude[] = {7, 8, 12, 5, 11, 1, 14};
    int exclude[] = {11, 28, 33};
    for(int j : exclude) if(j==i) return false;
    return true;
}

#define F(i) for(__int128 i=0; i<99999999LL; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0,999);
    for(int i=0; i<3; i++) {
        int a = dis(gen), b = dis(gen), c = dis(gen)/3;
        if(a>b) swap(a, b);
        cout << a << ' ' << b << ' ' << c << '\n';
    }
//    for(int i=0; i<5000; i++)
//        cout << dis(gen) << ' ';
//    for(int ii=0; ii<10; ii++) {
//        auto st = clock();
//        __int128 ans = 0;
//        F(i) { __int128 a = dis(gen);
//            ans += a * 63; }
//        cout << (clock() - st) << ' ';
//        st = clock();
//        F(i) { __int128 a = dis(gen);
//            ans += a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a+a; }
//        cout << (clock() - st) << ' ';
//        st = clock();
//        F(i) { __int128 a = dis(gen);
//            ans += (a<<6)-a; }
//        cout << (clock() - st) << ' ';
//        st = clock();
//        F(i) { __int128 a = dis(gen);
//            ans += (a << 5) + (a << 4) + (a << 3)+ (a << 2)+ (a << 1) + a; }
//        cout << clock() - st << '\n';
//        if (ans == 0) cout << (long long) ans;
//    }
}
