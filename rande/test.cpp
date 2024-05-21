#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen(R"(C:\Users\ryans\Desktop\Coding\RandE\output.txt)", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0,50);
    cout << "1000 1000\n300 300\n950 950\n";
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++)
            cout << dis(gen) << ' ';
        cout << '\n';
    }
}