#include <bits/stdc++.h>
#define int long long
#define INF 2147483647463
using namespace std;

struct point { int x, y; };
struct pa { point p; int dist; };

int destx, desty; 
point dest;

double euclidDist(point a, point b) {
    double x = (a.x-b.x) * (a.x-b.x);
    double y = (a.y-b.y) * (a.y-b.y);
    return sqrt(x+y);
}

struct cmp {
    bool operator()(pa a, pa b) {
        return a.dist+ euclidDist(dest, a.p) > b.dist+ euclidDist(dest, b.p);
    }
};

void printMD(vector<vector<int>> &mindist, vector<string> &map, int height, int width) {
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            if(map[y][x]=='1') printf("=== ");
            else if(mindist[y][x]==INF) printf("... ");
            else printf("%3lld ", mindist[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

signed main()
{
    int height, width; cin >> height >> width;
    int startx, starty; cin >> startx >> starty;
    cin >> destx >> desty;
    point tempd(destx, desty); dest = tempd;
    vector<int> mindistt(width, INF);
    vector<vector<int>> mindist(height, mindistt); //INF => not visited
    point start(startx, starty);
    vector<string> map;
    for(int i=0; i<height; i++)
    {
        string s; cin >> s; map.push_back(s);
    }
    priority_queue<pa, vector<pa>, cmp> pq;
    pq.emplace(start, 0);
    mindist[start.y][start.x] = 0;
    while(!pq.empty()) {
        pa top = pq.top();
        pq.pop();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int i=0; i<4; i++) {
            int nx = top.p.x + dx[i], ny = top.p.y + dy[i];
            point nxtp(nx, ny);
            if(nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
            if(map[ny][nx] == '1') continue;
            if(mindist[ny][nx] <= top.dist + 1) continue;
            mindist[ny][nx] = top.dist + 1;
            pq.emplace(nxtp, mindist[ny][nx]);
        }
        printMD(mindist, map, height, width);
        //if(mindist[dest.y][dest.x] != INF) break;
    }
    printf("%lld", mindist[dest.y][destx]);
}
