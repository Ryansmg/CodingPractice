#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 3197. 백조의 호수
// #disjoint_set #bfs

struct tri {
    int a, b, c;
    tri(){}
    tri(int x, int y, int z) {
        a=x;b=y;c=z;
    }
};

int findP(vector<int> &parent, int n) {
    //if(n==-1) cout <<"!";
    if(n==-1) return -1;
    if(parent[n] == n) return n;
    return parent[n] = findP(parent, parent[n]);
}

void printLake(vector<vector<int>> &lake, vector<int> &parent) {
    cout << "\n";
    for(auto a : lake){
        for(auto c : a ) {
            if(c==-1) cout << "X";
            else if(c==-2) cout << "Q";
            else cout << findP(parent, c);
        }
        cout << endl;
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<int> temp;
    vector<bool> tmp(c, false);
    vector<vector<int>> lake(r, temp);
    vector<vector<bool>> visited(r, tmp);
    int l1 = -1, l2 = -1;
    pair<int, int> l1pos, l2pos;
    bool l1posset = false;
    int partcnt = 0;
    for(int i=0; i<r; i++) {
        string s; cin >> s;
        for(int j=0; j<c; j++) 
        {
            char ch = s[j];
            if(ch == 'L') {
                if(!l1posset) {
                    l1posset = true;
                    l1pos = {i, j};
                } else {
                    l2pos = {i, j};
                }
                lake[i].push_back(0);
            }
            else lake[i].push_back((ch=='.'?0:-1));
        }
    }
    vector<int> p(1, -1);
    queue<tri> nxt;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(lake[i][j] != 0) continue;
            if(visited[i][j]) continue;
            visited[i][j] = true;
            partcnt++;
            p.push_back(partcnt);
            queue<pair<int, int>> bfs;
            bfs.emplace(i, j);
            while(!bfs.empty()) {
                auto fr = bfs.front(); bfs.pop();
                if(lake[fr.first][fr.second] != 0) continue;
                lake[fr.first][fr.second] = partcnt;
                if(fr.first == l1pos.first && fr.second == l1pos.second) l1 = partcnt;
                else if(fr.first == l2pos.first && fr.second == l2pos.second) l2 = partcnt;
                int dx[] = { 1, -1, 0, 0 };
                int dy[] = { 0, 0, 1, -1 };
                for(int k=0; k<4; k++) {
                    if(fr.first+dy[k]<0 || fr.first+dy[k]>=r || fr.second+dx[k]<0 || fr.second+dx[k]>=c) continue;
                    if(visited[fr.first+dy[k]][fr.second+dx[k]]) continue;
                    visited[fr.first+dy[k]][fr.second+dx[k]] = true;
                    if(lake[fr.first+dy[k]][fr.second+dx[k]] == -1) {
                        nxt.emplace(fr.first+dy[k], fr.second+dx[k], partcnt);
                    }
                    if(lake[fr.first+dy[k]][fr.second+dx[k]] != 0) continue;
                    bfs.emplace(fr.first+dy[k], fr.second+dx[k]);
                }
            }
        }
    }
    nxt.emplace(-1, -1, -1);
    int day = 0;
    if(findP(p, l1) == findP(p, l2)) {
        cout << day;
        return 0;
    }
    visited.clear();
    vector<vector<bool>> vis(r, tmp);
    while(1) {
        day++;
        while(1) {
            tri fr = nxt.front(); nxt.pop();
            if(fr.a == -1) break;
            vis[fr.a][fr.b] = true;
            if(lake[fr.a][fr.b] == -1) lake[fr.a][fr.b] = findP(p, fr.c);
            else p[findP(p, fr.c)] = findP(p, lake[fr.a][fr.b]);
                int dx[] = { 1, -1, 0, 0 };
                int dy[] = { 0, 0, 1, -1 };
                for(int i=0; i<4; i++) {
                    int ny = fr.a+dy[i];
                    int nx = fr.b+dx[i];
                    if(nx<0 || ny<0 || nx>=c || ny>=r) continue;
                    if(lake[ny][nx] != -1 && findP(p,lake[ny][nx]) != findP(p,lake[fr.a][fr.b])) {
                        p[findP(p, lake[ny][nx])] = findP(p, lake[fr.a][fr.b]);
                    }
                }
                if(findP(p, l1) == findP(p, l2)) {
                    cout << day;
                    return 0;
                }
                
            for(int i=0; i<4; i++) {
                int ny = fr.a+dy[i];
                int nx = fr.b+dx[i];
                if(nx<0 || ny<0 || nx>=c || ny>=r) continue;
                if(lake[ny][nx] != -1 || vis[ny][nx]) continue;
                nxt.emplace(ny, nx, fr.c);
                vis[ny][nx] = true;
            }
        }
        nxt.emplace(-1, -1, -1);
        //printLake(lake, p);
    }
}
