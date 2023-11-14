#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#define int_max 2100000000
using namespace std;

//가장 긴 증가하는 부분 수열 5

//lower_bound : 오름차순 정렬된 수열에 대해 사용 가능,
//이진 탐색으로 주어진 수 이상의 값을 담은 최소의 index를 반환

int main()
{
    int n; //수열의 크기
    scanf("%d", &n);
    vector<int> in, lis, lis_ind(n), prev(n+1);
    for(int i=0; i<n; i++) {
        int a;
        scanf(" %d", &a);
        in.push_back(a);
        lis.push_back(int_max);
    }

    for(int i=0; i<n; i++) {
        auto iter = lower_bound(lis.begin(), lis.end(), in[i]);
        int ind = iter - lis.begin();
        *iter = in[i];
        lis_ind[ind] = i;
        if(ind == 0) prev[i] = -1;
        else prev[i] = lis_ind[ind-1];
    }

    int i = lower_bound(lis.begin(), lis.end(), int_max) - lis.begin();
    printf("%d\n", i);
    int ind = lis_ind[i-1];
    vector<int> ansInd(i);
    int curi = i-1;
    while(curi != -1){
        ansInd[curi] = ind;
        ind = prev[ind];
        curi--;
    }
    for(int j=0; j<i; j++) printf("%d ", in[ansInd[j]]);
}