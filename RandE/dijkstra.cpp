#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#define int long long
//#define double long double
#ifdef double
#define printdouble "%Lf\n"
#else
#define printdouble "%f\n"
#endif
#define double float
#define INF 2147483640
using namespace std;

// A* algorithm

// 입력:
// width height
// startx starty
// endx endy
// map(width * height) : 높이가 주어짐.
/* 예시 입력:
40 30
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
40 30
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

double euclidDist(const point &a, const point &b, const int &ha, const int &hb) {
    double x = (a.x-b.x) * (a.x-b.x);
    double y = (a.y-b.y) * (a.y-b.y);
    return sqrt(x+y+(hb-ha)*(hb-ha));
}

double euclidDist(const point &a, const point &b) {
    double x = (a.x-b.x) * (a.x-b.x);
    double y = (a.y-b.y) * (a.y-b.y);
    return sqrt(x+y);
}

double edFromH(const int &h1, const int &h2, const double &td) {
    double ans = sqrt(td + (h2-h1)*(h2-h1));
    return ans;
}

vector<vector<int>> hmap;
int cmpCnt = 0;
struct cmp {
    bool operator()(const pa &a, const pa &b) {
        cmpCnt++;
        return a.dist
               > b.dist;
    }
};

void printMD(const vector<vector<double>> &mindist, const vector<vector<int>> &map, const int &height, const int &width) {
    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            if(mindist[y][x]==INF) printf(" ");
            else printf("O");
        }
        printf("\n");
    }
    printf("\n");
}

bool printPath = false;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen(R"(C:\Users\ryans\Desktop\Coding\RandE\output.txt)", "r", stdin);
    freopen(R"(C:\Users\ryans\Desktop\Coding\RandE\dijkOutput.txt)", "w", stdout);
    int height, width; cin >> width >> height;
    int startx, starty; cin >> startx >> starty;
    cin >> destx >> desty;
    point tempd(destx, desty); dest = tempd;
    vector<double> mindistt(width, INF);
    vector<vector<double>> mindist(height, mindistt); //INF => not visited
    point start(startx, starty);
    vector<int> temp;
    vector<point> temp2(width);
    vector<vector<int>> hmapt(height, temp);
    hmap = hmapt;
    vector<vector<point>> pre(height, temp2);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++) {
            int t;
            cin >> t;
            hmap[i].push_back(t);
            pre[i].push_back({j, i});
        }
    }
    clock_t startClock = clock();
    priority_queue<pa, vector<pa>, cmp> pq;
    pq.emplace(start, 0);
    mindist[start.y][start.x] = 0;
    int emplaceCnt = 0, popCnt = 0;
    while(!pq.empty()) {
        pa top = pq.top();
        pq.pop(); popCnt++;
        int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
        bool haveChange = false;
        for(int i=0; i<8; i++) {
            int nx = top.p.x + dx[i], ny = top.p.y + dy[i];
            point nxtp(nx, ny);
            if(nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
            double td = abs(dx[i]) + abs(dy[i]);
            if(mindist[ny][nx] <= top.dist + edFromH(hmap[top.p.y][top.p.x], hmap[ny][nx], td)) continue;
            mindist[ny][nx] = top.dist + edFromH(hmap[top.p.y][top.p.x], hmap[ny][nx], td);
            pre[ny][nx] = top.p;
            pq.emplace(nxtp, mindist[ny][nx]);
            haveChange = true;
            emplaceCnt++;
        }
        //if(haveChange) printMD(mindist, map, height, width);
        //if(mindist[dest.y][dest.x] != INF) break;
    }
    cout << emplaceCnt << " " << popCnt << ' ' << cmpCnt;
    cout << "\n==============================\n";
    cout << "Time : " << static_cast<double>(clock() - startClock) << " (ms)\n";
    cout << "==============================\n";
    cout.flush();
    printf(printdouble, mindist[dest.y][destx]);
    if(!printPath) return 0;
    printMD(mindist, hmap, height, width);
    for(int i=0; i<height; i++)
        fill(mindist[i].begin(), mindist[i].end(), INF);
    int bty = dest.y, btx = destx;
    while(!(bty==starty && btx==startx)) {
        mindist[bty][btx] = 1;
        point pp = pre[bty][btx];
        bty = pp.y; btx = pp.x;
    }
    printMD(mindist, hmap, height, width);

}
