#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 2147483647463
using namespace std;

// A* 알고리즘

// 입력:
// height width
// startx starty
// endx endy
// map(width * height) : 높이가 주어짐.
/* 예시 입력:
30 40
19 15
39 29
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 2 1 2 3 4 3 3 2 3 4 0 2 1 0 0
0 0 1 2 1 2 3 4 3 3 2 3 4 0 2 1 0 0 2 2 1 0 1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1
1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3 2 1 1 1 0 0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 1 0 0 0 0 1 1 2 3 2 1 1 3
0 0 1 1 2 1 0 0 0 0 1 1 2 3 2 1 1 3 2 1 0 0 0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3
0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3 2 2 1 0 1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1
1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 1 1 1 1 0 0 2 3 2 1 0 1 1 2 3 2
0 0 1 1 1 1 0 0 2 3 2 1 0 1 1 2 3 2 1 1 1 0 0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2 1 1 0 0 2 2 1 0 0 0 1 2 3 4 3 2 2 1 0 0 0 1
2 2 1 0 0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3 1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1
1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3
0 0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3 2 1 1 1 0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1
0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3 2 2 1 0 1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1
1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 1 1 1 1 0 0 2 3 2 1 0 1 1 2 3 2
0 0 1 1 1 1 0 0 2 3 2 1 0 1 1 2 3 2 1 1 1 0 0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2 1 1 0 0 2 2 1 0 0 0 1 2 3 4 3 2 2 1 0 0 0 1
2 2 1 0 0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3 1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1
1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3
0 0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3 2 1 1 1 0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 2 1 2 3 4 3 3 2 3 4 0 2 1 0 0
0 0 1 2 1 2 3 4 3 3 2 3 4 0 2 1 0 0 2 2 1 0 1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1
1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3 2 1 1 1 0 0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 1 0 0 0 0 1 1 2 3 2 1 1 3
0 0 1 1 2 1 0 0 0 0 1 1 2 3 2 1 1 3 2 1 0 0 0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3
*/
/*
30 40
19 15
39 29
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 3 92 91 91 0 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 2 1 2 93 94 93 3 2 3 4 0 2 1 0 0
0 0 1 2 1 2 3 4 3 3 2 3 4 0 2 1 0 0 2 2 1 0 1 1 1 2 3 4 91 91 92 1 0 1 1 1 2 3 4 1
1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 93 4 1 1 2 1 0 0 0 1 1 2 3 92 91 91 1 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 1 0 0 0 1 1 92 3 2 1 1 1 0 0 0 0 0 1 2 91 91 90 0 0 0 0 0 0 1 2 1
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 91 2 1 1 0 0 0 0 0 1 1 2 1 90 90 90 0 1 1 2 3 2 1 1 3
0 0 1 1 2 1 0 0 0 0 1 1 2 3 2 91 1 3 2 1 0 0 0 0 1 2 3 4 93 92 92 1 0 0 0 1 2 3 4 3
0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 93 4 3 2 2 1 0 1 1 1 2 3 4 91 91 92 1 0 1 1 1 2 3 4 1
1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 93 4 1 1 2 1 0 0 0 1 1 1 1 90 90 92 3 2 1 0 1 1 2 3 2
0 0 1 1 1 1 0 0 2 3 2 1 0 1 1 92 3 2 1 1 1 0 0 0 0 0 1 2 91 91 90 0 0 0 0 0 0 1 2 1
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 91 2 1 1 0 0 0 0 0 1 1 2 3 92 91 91 0 0 0 0 1 1 2 3 2
0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 92 3 2 1 1 0 0 2 2 1 0 0 0 91 92 93 4 3 2 2 1 0 0 0 1
2 2 1 0 0 0 1 2 3 4 3 2 2 1 0 90 0 1 2 3 4 3 1 1 1 2 3 4 91 91 92 1 0 1 1 1 2 3 4 1
1 1 91 92 93 94 1 91 92 91 90 91 1 1 2 3 4 1 1 2 1 0 0 0 0 1 1 2 93 92 91 1 1 0 0 0 1 1 2 3
0 0 90 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3 2 1 1 1 0 0 0 0 1 2 91 91 90 0 0 0 0 0 0 1 2 1
0 0 91 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3 2 2 1 0 1 1 1 2 3 4 91 91 92 1 0 1 1 1 2 3 4 1
1 1 91 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 1 1 1 1 90 90 92 3 2 1 0 1 1 2 3 2
0 0 91 1 1 1 0 0 2 3 2 1 0 1 1 2 3 2 1 1 1 0 0 0 0 0 1 2 91 91 90 0 0 0 0 0 0 1 2 1
0 0 90 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 3 92 91 91 0 0 0 0 1 1 2 3 2
0 0 91 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2 1 1 0 0 2 2 1 0 0 0 91 92 93 4 3 2 2 1 0 0 0 1
2 2 91 0 0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3 1 1 1 2 3 4 91 91 92 1 0 1 1 1 2 3 4 1
1 1 91 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 0 1 1 2 93 92 91 1 1 0 0 0 1 1 2 3
0 0 90 1 1 2 3 2 1 1 1 0 0 0 1 1 2 3 2 1 1 1 0 0 0 0 1 2 91 91 90 0 0 0 0 0 0 1 2 1
0 0 90 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2
0 0 91 1 2 3 2 1 1 0 0 0 0 1 1 2 3 2 1 1 0 0 0 0 1 2 1 2 3 4 3 3 2 3 4 0 2 1 0 0
0 0 91 2 1 2 3 4 3 3 2 3 4 0 2 1 0 0 2 2 1 0 1 1 1 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1
1 1 91 2 3 4 1 1 2 1 0 1 1 1 2 3 4 1 1 2 1 0 0 0 1 1 2 3 92 91 1 1 0 0 0 1 1 2 3 2
0 0 991 991 992 993 992 991 991 991 990 990 990 991 991 992 939 929 91 91 91 90 90 90 90 90 91 92 91 91 90 90 90 90 90 90 90 91 92 91
0 0 0 0 1 2 1 1 0 0 0 0 0 0 0 1 2 1 1 0 0 0 0 0 1 1 2 1 0 0 0 0 1 1 2 3 2 1 1 3
0 0 1 1 2 1 0 0 0 0 1 1 2 3 2 1 1 3 2 1 0 0 0 0 1 2 3 4 3 2 2 1 0 0 0 1 2 3 4 3
*/

struct point { int x, y; };
struct pa { point p; double dist; };

int destx, desty; 
point dest;

double euclidDist(point a, point b) {
    double x = (a.x-b.x) * (a.x-b.x);
    double y = (a.y-b.y) * (a.y-b.y);
    return sqrt(x+y);
}

double edFromH(int h1, int h2) {
    double ans = sqrt(1.0 + (h2-h1)*(h2-h1));
    return ans;
}

struct cmp {
    bool operator()(pa a, pa b) {
        return a.dist+ euclidDist(dest, a.p) > b.dist+ euclidDist(dest, b.p);
    }
};

void printMD(vector<vector<double>> &mindist, vector<vector<int>> &map, int height, int width) {
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            if(mindist[y][x]==INF) printf(".. ");
            else printf("%2lld ", (int)mindist[y][x]);
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
    vector<double> mindistt(width, INF);
    vector<vector<double>> mindist(height, mindistt); //INF => not visited
    point start(startx, starty);
    vector<int> temp;
    vector<point> temp2(width);
    vector<vector<int>> map(height, temp);
    vector<vector<point>> pre(height, temp2);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++) {
            int t;
            cin >> t;
            map[i].push_back(t);
            pre[i].push_back({j, i});
        }
    }
    priority_queue<pa, vector<pa>, cmp> pq;
    pq.emplace(start, 0);
    mindist[start.y][start.x] = 0;
    while(!pq.empty()) {
        pa top = pq.top();
        pq.pop();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        bool haveChange = false;
        for(int i=0; i<4; i++) {
            int nx = top.p.x + dx[i], ny = top.p.y + dy[i];
            point nxtp(nx, ny);
            if(nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
            if(mindist[ny][nx] <= top.dist + edFromH(map[top.p.y][top.p.x], map[ny][nx])) continue;
            mindist[ny][nx] = top.dist + edFromH(map[top.p.y][top.p.x], map[ny][nx]);
            pre[ny][nx] = top.p;
            pq.emplace(nxtp, mindist[ny][nx]);
            haveChange = true;
        }
        //if(haveChange) printMD(mindist, map, height, width);
        if(mindist[dest.y][dest.x] != INF) break;
    }
    printMD(mindist, map, height, width);
    printf("%Lf\n", mindist[dest.y][destx]);
    for(int i=0; i<height; i++)
        fill(mindist[i].begin(), mindist[i].end(), INF);
    int bty = dest.y, btx = destx;
    while(!(bty==starty && btx==startx)) {
        mindist[bty][btx] = 1;
        point pp = pre[bty][btx];
        bty = pp.y; btx = pp.x;
    }
    printMD(mindist, map, height, width);
}
