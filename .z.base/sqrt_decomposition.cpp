#include <bits/stdc++.h>
#define int long long
#define lint __int128
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(vec) (vec).begin(), (vec).end()

using namespace std;
template <typename T> using v = vector<T>;
using ii = pair<int, int>;
template <typename T> using pq = priority_queue<T>;

template <typename T> void compress(v<T> &v, bool autosort=true) { if(autosort) sort(all(v)); v.erase(v.unique(all(v)), v.end()); }
int input() { int t=llmax; cin >> t; return t;}
lint linput() { return (lint) input(); }
template <typename T> void print(T i, const string& end="") { cout << i << end; }
void print(lint i, const string& end="") { cout << (int)i << end;}
template <typename T> T temp() { T t; return t; }

// 14504. 수열과 쿼리 18
// #sqrt_decomposition

signed main()
{
    fastio;
    int n = input(), sqrtSize = (int) sqrt(n),
            bucketCnt = (n / sqrtSize) + 5;
    v<v<int>> arr(bucketCnt, temp<v<int>>());
    v<v<int>> buckets(bucketCnt, temp<v<int>>());
    for(int i=0; i<n/sqrtSize; i++)
        for (int j = 0; j < sqrtSize; j++) {
            int t = input();
            buckets[i].push_back(t);
            arr[i].push_back(t);
        }
    for(int i=0; i<n%sqrtSize; i++){
        int t = input();
        buckets[n/sqrtSize].push_back(t);
        arr[n/sqrtSize].push_back(t);
    }
    for(v<int> &v : buckets) sort(all(v));
    int m = input();
    const int query = 1, update = 2;
    for(int qi=0; qi<m; qi++) {
        int type = input();
        assert(type == query || type == update);
        if(type == query) {
            int l, r, k, ans=0; // k보다 큰 원소의 개수 출력
            cin >> l >> r >> k;
            l--; r--;
            if(l/sqrtSize == r/sqrtSize) {
                // l과 r이 속한 bucket이 같은 경우 따로 처리
                for(int i=l; i<=r; i++)
                    ans += (arr[i/sqrtSize][i%sqrtSize] > k ? 1 : 0);
            } else {
                // 범위를 온전히 포함하는 bucket은 upper_bound로 처리, 아니면 일일이 계산
                int lBInd = l/sqrtSize+1, rBInd = r/sqrtSize-1;
                if(l%sqrtSize==0) lBInd--;
                if(r%sqrtSize==sqrtSize-1) rBInd++;
                for(int i=l; i<lBInd*sqrtSize; i++)
                    ans += (arr[i/sqrtSize][i%sqrtSize] > k ? 1 : 0);
                for(int i=r; i>rBInd*sqrtSize+sqrtSize-1; i--)
                    ans += (arr[i/sqrtSize][i%sqrtSize] > k ? 1 : 0);
                for(int i=lBInd; i<=rBInd; i++)
                    ans += buckets[i].end() - upper_bound(all(buckets[i]), k);
            }
            print(ans, "\n");
        }
        if(type == update) {
            int updInd = input()-1, val = input();
            int bucketInd = updInd/sqrtSize;
            int ind = updInd%sqrtSize;
            int preVal = arr[bucketInd][ind];
            arr[bucketInd][ind] = val;
            *lower_bound(all(buckets[bucketInd]), preVal) = val;
            sort(all(buckets[bucketInd]));
        }
    }
}
