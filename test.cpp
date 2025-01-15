#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<vector<int>> g1, g2;
vector<int> visited, order;
vector<vector<int>> sccs;
vector<string> li;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};

int t(int x) {
    return (x < 0) ? (-x) * 2 : x * 2 - 1;
}

void dfs1(int node) {
    visited[node] = 1;
    for (int next : g1[node]) {
        if (!visited[next]) dfs1(next);
    }
    order.push_back(node);
}

void dfs2(int node, vector<int>& scc) {
    visited[node] = 1;
    scc.push_back(node);
    for (int next : g2[node]) {
        if (!visited[next]) dfs2(next, scc);
    }
}

int t2(int i, int j){
    return 4*(i*(m+2)+j);
}

void mat(int a, int b){
    g1[t(-a)].push_back(t(b));
    g1[t(-b)].push_back(t(a));
    g2[t(a)].push_back(t(-b));
    g2[t(b)].push_back(t(-a));
}

#define filein freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "r", stdin)
#define fileout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)
#define inputout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "w", stdout)
#define outputin freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "r", stdin)
#define ansout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\ans.txt)", "w", stdout)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein; fileout;
    int t0;
    cin >> t0;
    while (t0--){
        cin >> n >> m;
        v = 8 * (n+2) * (m+2);
        string ans = "YES";

        g1.clear();
        g2.clear();
        g1.resize(v + 1);
        g2.resize(v + 1);

        visited.clear();
        visited.resize(v + 1, 0);

        order.clear();
        sccs.clear();
        li.clear();

        string s;

        li.push_back(string(m+2, '.'));
        for (int i = 0; i < n; i++) {
            cin >> s;
            li.push_back("." + s + ".");
        }
        li.push_back(string(m+2, '.'));

        int cntb = 0, cntw = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (li[i][j] == 'B'){
                    if (li[i-1][j] == '.' || li[i+1][j] == '.'){
                        if (li[i-1][j] == '.' && li[i+1][j] == '.') ans = "NO";
                        if (li[i-1][j] == '.') mat(t2(i,j)+1, t2(i,j)+1);
                        else mat(t2(i,j), t2(i,j));
                    } else {
                        //cout << "1 " << i << ' ' << j << '\n';
                        mat(t2(i,j), t2(i,j)+1);
                    }
                    if (li[i][j-1] == '.' || li[i][j+1] == '.'){
                        if (li[i][j-1] == '.' && li[i][j+1] == '.') ans = "NO";
                        if (li[i][j-1] == '.') mat(t2(i,j)+3, t2(i,j)+3);
                        else mat(t2(i,j)+2, t2(i,j)+2);
                    } else {
                        //cout << "2 " << i << ' ' << j << '\n';
                        mat(t2(i,j)+2,t2(i,j)+3);
                    }
                    cntb++;
                }
                else if (li[i][j] == 'W'){
                    int z=0;
                    for(int k=0;k<4;k++){
                        int di=i+xx[k], dj=j+yy[k];
                        int dz=t2(di,dj)+k;
                        if(li[di][dj]!='B') continue;
                        z++;
                        for(int k2=k+1;k2<4;k2++){
                            int di2=i+xx[k2], dj2=j+yy[k2];
                            int dz2=t2(di2,dj2)+k2;
                            if(li[di2][dj2]!='B') continue;
                            //cout << "3 " << i << ' ' << j << '\n';
                            mat(-dz,-dz2);
                        }
                    }
                    if(z==0) ans="NO";
                    cntw++;
                }
            }
        }

        if (ans == "NO" || cntw != cntb * 2){
            cout << "NO\n";
            continue;
        }

        for (int i = 1; i <= v; i++) {
            if (!visited[i]) dfs1(i);
        }

        fill(visited.begin(), visited.end(), 0);
        reverse(order.begin(), order.end());

        for (int node : order) {
            if (!visited[node]) {
                vector<int> scc;
                dfs2(node, scc);
                sccs.push_back(scc);
            }
        }

        vector<int> comp(v + 1, -1);
        int comp_idx = 0;
        for (const auto& scc : sccs) {
            for (int node : scc) {
                if (comp[node] == -1) {
                    comp[node] = comp_idx;
                }
            }
            comp_idx++;
        }

        for (int i = 1; i <= 4*(n+2)*(m+2); i++) {
            if (comp[t(i)] == comp[t(-i)]) {
                ans = "NO";
                break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}