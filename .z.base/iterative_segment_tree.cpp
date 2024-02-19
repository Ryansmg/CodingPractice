#include <iostream>
#include <vector>
#define ll long long

using namespace std;

//#2042 구간 합 구하기 
//비재귀 세그먼트 트리 ( https://bit.ly/48AJUn0 참고)
//iterative segment tree

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, //수의 개수
    m, //수 변경 횟수
    k; //합 구하는 횟수
    cin >> n >> m >> k;
    //1~n-1 : 합 노드, n~2n-1 : 잎 노드
    vector<ll> tree(4*n);
    for(ll i=n; i<2*n; i++) cin >> tree[i];

    //init
    for(ll i = n-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1]; //[i*2]+[i*2+1]과 같음
    
    for(ll ii = 0; ii < m+k; ii++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        b--; //입력 b는 1~n, 사용하는 b는 0~n-1
        if(a==1){ //b번째 수 c로 바꾸기 (update)
            tree[n+b] = c;
            for(ll i = n+b; i>1; i>>=1) //(i>>=1) == (i/=2)
                tree[i>>1] = tree[i] + tree[i^1];
                //tree[i] + tree[i^1]은 i>>1의 기우성에 상관없이 자식 노드 2개의 합이 된다.
        }
        else { //b~c번째 수들의 합 출력
            //query, [l,r) (l 포함, r 비포함)
            ll l = b+n, r = c+n; //(c-1)+n+1 => c-1: b와 같은 이유, +1: 비포함
            ll sum=0;
            for(; l<r; l>>=1, r>>=1){
                if(l&1) sum += tree[l++]; //l이 홀수이면 tree[l]의 부모 노드는 범위를 벗어남
                if(r&1) sum += tree[--r]; //r이 홀수이면 tree[r-1]의 부모 노드는 범위를 벗어남
            }
            cout << sum << "\n";
        }
    }
}
