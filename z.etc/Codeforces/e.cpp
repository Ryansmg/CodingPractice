#include <iostream>
using namespace std;

int stringCompare(string a, string b) {
    int len = a.length();
    int wr = 0;
    for(int i=0; i<len; i++) {
        if(a[i]!=b[i]) wr++;
        if(wr>1) break;
    }
    return wr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int ti=0; ti<t; ti++) {
        int n; string s;
        cin >> n >> s;
        for(int i=1; i<=n; i++) {
            if(n%i!=0) continue;
            for(int st = 0; st<n; st+=i) {
            string origin = s.substr(st, i);
            int comp = 0;
            for(int j=0; j<n; j+=i) {
                comp += stringCompare(origin, s.substr(j, i));
                if(comp > 1) break;
            }
            if(comp <= 1) {
                cout << i << "\n";
                goto end;
            } 
            }
        }
        end:
    }
}
