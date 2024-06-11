#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
bool useDebugPrints = false;
#define mcl if(useDebugPrints)
//#define int long long
//#define double long double
#ifdef double
#define printdouble "%Lf\n"
#else
#define printdouble "%f\n"
#endif
#define INF 2147483640
using namespace std;
#define double float

#pragma region information
// A* 알고리즘

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
#pragma endregion

struct point { int x, y; };
struct pa { point p; double dist; double destdist; };

int destx, desty; 
point dest;

double euclidDist(const point &a, const point &b, const int &ha, const int &hb) {
    double x = (a.x-b.x) * (a.x-b.x) * 100;
    double y = (a.y-b.y) * (a.y-b.y) * 100;
    return sqrt(x+y+(hb-ha)*(hb-ha));
}

double euclidDist(const point &a, const point &b) {
    double x = (a.x-b.x) * (a.x-b.x) * 100;
    double y = (a.y-b.y) * (a.y-b.y) * 100;
    return sqrt(x+y);
}

long edfht = 0;
double edFromH(const int &h1, const int &h2, const double &td) {
    clock_t a;
    mcl a = clock();
    double ans = sqrt(td*100 + (h2-h1)*(h2-h1));
    mcl {edfht += clock()-a;}
    return ans;
}

vector<vector<int>> hmap;

const double edWeight = 1.6;
int cmpCnt = 0;
struct cmp {
    bool operator()(const pa &a, const pa &b) {
        cmpCnt++;
        return a.destdist > b.destdist;
    }
};

void printMD(const vector<vector<double>> &mindist, const int &height, const int &width) {
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
    clock_t rsc = clock();
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen(R"(C:\Users\ryans\Desktop\Coding\RandE\output.txt)", "r", stdin);
    freopen(R"(C:\Users\ryans\Desktop\Coding\RandE\astarOutput.txt)", "w", stdout);
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
    double emplaceTime = 0, searchPreTime = 0;
    priority_queue<pa, vector<pa>, cmp> pq;
    pq.emplace(start, 0, euclidDist(start, dest));
    mindist[start.y][start.x] = 0;
    int emplaceCnt = 0, popCnt = 0;
    const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    const int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
    clock_t startClock = clock();
    while(!pq.empty()) {
        pa top = pq.top();
        pq.pop(); popCnt++;
        //bool haveChange = false;
        for(int i=0; i<8; i++) {
            int nx = top.p.x + dx[i], ny = top.p.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
            clock_t scht, emc;
            mcl scht = clock();
            double ttd = top.dist +
                    edFromH(hmap[top.p.y][top.p.x], hmap[ny][nx],
                            abs(dx[i]) + abs(dy[i]));
            mcl searchPreTime += clock() - scht;
            if(mindist[ny][nx] <= ttd) {
                continue;
            }
            mindist[ny][nx] = ttd;
            pre[ny][nx] = top.p;
            mcl searchPreTime += clock() - scht;
            mcl emc = clock();
            point nxtp(nx, ny);
            pq.emplace(nxtp, mindist[ny][nx],
                       euclidDist(nxtp, dest)*edWeight + mindist[ny][nx]);
            mcl emplaceTime += clock() - emc;
            //haveChange = true;
            emplaceCnt++;
        }
        //if(haveChange) printMD(mindist, map, height, width);
        if(mindist[dest.y][dest.x] != INF) break;
    }
    auto time = clock() - startClock;
    cout << emplaceCnt << ' ' << popCnt << ' ' << cmpCnt;
    cout << "\n==============================\n";
    cout << "Time : " << time << " (ms)\n";
    cout << "Reading time : " << startClock-rsc << " (ms)\n";
    mcl cout << "Emplace time : " << emplaceTime << " (ms)\n";
    mcl cout << "Search time : " << searchPreTime << " (ms)\n";
    mcl cout << "edFromH time : " << edfht << " (ms)\n";
    cout << "==============================\n";
    cout.flush();
    if(printPath) {
        printMD(mindist, height, width);
    }
    float distans = mindist[dest.y][destx];
    cout.flush();
    for (int i = 0; i < height; i++)
        fill(mindist[i].begin(), mindist[i].end(), INF);
    int bty = dest.y, btx = destx;
    int cnt = 0;
    while (!(bty == starty && btx == startx)) {
        mindist[bty][btx] = 1;
        point pp = pre[bty][btx];
        double diff = (-hmap[bty][btx] + hmap[pp.y][pp.x])/10.0;
        double xdiff = pp.x-btx; 
        double ydiff = pp.y-bty; 
        cout << btx*10+1 << ' ' << bty*10+1 << ' ' << hmap[bty][btx] << '\n';
        cnt++;
        for(int i=1; i<=9; i++) {
            cnt++;
            cout << (int)round(btx*10+1+i*xdiff) << ' ' << (int)round(bty*10+1+i*ydiff) << ' ' << hmap[bty][btx] + i*diff << '\n';
        }
        bty = pp.y;
        btx = pp.x;
    }
    cout << startx*10+1 << ' ' << starty*10+1 << ' ' << hmap[starty][startx] << '\n';
    cnt++;
    cout << "cnt:" << cnt << '\n';
    printf(printdouble, distans);
}
