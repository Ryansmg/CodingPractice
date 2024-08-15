#include <iostream>
using i64 = long long;
#define forn(i, a) for(i64 i=0; i<a; i++)
#define forf(i, a, b) for(i64 i=a; i<=b; i++)
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)

i64 temp[200000];

void merge(i64 arr[], i64 left, i64 mid, i64 right){
    i64 i = left, j = mid+1, k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    if(i > mid) forf(l, j, right) temp[k++] = arr[l];
    else forf(l, i, mid) temp[k++] = arr[l];
    forf(l, left, right) arr[l] = temp[l];
}

void merge_sort(i64 list[], i64 left, i64 right){
    if(left < right){
        i64 mid = (left+right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main() {
    fastio;
    i64 n = 0; std::cin >> n;
    i64 arr[n];
    forn(i, n) std::cin >> arr[i];
    merge_sort(arr, 0, n-1);
    for(i64 i : arr) std::cout << i << ' ';
}
