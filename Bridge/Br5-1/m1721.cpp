#include <iostream>
#include <vector>
#define fio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define v vector
#define getnm int n, m; cin >> n >> m;
#define x <<
#define p cout x
#define f for
#define pa { f(auto b : a) p b x " "; p "\n"; }
#define parr f(auto a : arr) pa
#define defarr v<int> t(m); v<v<int>> arr(n,t);
#define start fio getnm defarr
#define ef else f
using namespace std;

int main()
{
    start

    int k = 1;
    f(int i=n-1; i>=0; i--) {
        if(((n-i)%2)==1) { f(int j=m-1; j>=0; j--) arr[i][j] = k++;}
        ef(int j=0; j<m; j++) arr[i][j] = k++;
    }

    parr
}
