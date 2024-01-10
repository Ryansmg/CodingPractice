#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> temp(n+1, 0);
    vector<vector<int>> num(n+1, temp);
    vector<vector<int>> sum(n+1, temp);
    for(int i=1; i<=n; i++){
        num[i].push_back(0);
        for(int j=1; j<=n; j++)
        {
            int a; cin >> a; num[i][j]=(a);
            sum[i][j]=(a+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]);
        }
    }
    for(int i=0; i<m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] + sum[x1-1][y1-1] - sum[x2][y1-1] - sum[x1-1][y2] << "\n";
    }
}