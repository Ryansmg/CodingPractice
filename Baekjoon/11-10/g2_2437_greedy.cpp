#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//저울

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> w(n);
    for(int i=0; i<n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    
    int max=w[0];
    if(max!=1) {
        cout << 1;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(i==n){max++; break;}
        if(w[i] > max+1) {max++; break;}
        max += w[i];
    }
    cout << max;
}