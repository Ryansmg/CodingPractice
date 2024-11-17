//code by p1ckle/sft
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
//#define int long long int
#define X first
#define Y second
#define mid ((start+end)/2)
#define all(x) x.begin(), x.end()
#define ub(a, b) upper_bound(all(a), b)
#define lb(a, b) lower_bound(all(a), b)
#define pb push_back
#define endl '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dat = 20;
const int hgtc = 2000, widc = 2000, hed = 54;
int hgt = 400, wid = 584;

double D(pii a, pii b)  {return sqrt((abs(a.X-b.X))*abs(a.X-b.X)+double(abs(a.Y-b.Y))*abs(a.Y-b.Y));}

unsigned char B[hgtc][widc], G[hgtc][widc], R[hgtc][widc]; //BGR값을 담을 변수

double H[hgtc][widc], S[hgtc][widc], V[hgtc][widc]; //HSV값을 담을 변수
double tb[hgtc][widc], tg[hgtc][widc], tr[hgtc][widc]; //bgr(임시)
double cmx[hgtc][widc], cmn[hgtc][widc], cd[hgtc][widc]; //HSV 계산에 사용되는 중간값
bool oc[hgtc][widc], bh[hgtc][widc]; //바다 여부를 저장

float g[hgtc][widc];
int gx[hgtc][widc], gy[hgtc][widc]; //Sobel 필터 그레이디언트값

bool vis[hgtc][widc];
int cmpnum[hgtc][widc], cmpcnt = 0;
vi cmpv = {0};
vpii bfsst = {{0, 0}};
int cmpmx = 0; //bfs에 사용되는 변수들

double len[dat]; //축적에 따른 해안선 길이
pii lst[dat]; //해안선 길이 측정 시 bfs에서 사용되는 변수
double unit[dat]; //단위길이

void unitset() {
    
    for (int i = 0; i < dat; i++) unit[i] = (i+1)*5;
    
}

queue<pii> que;
void bfs(int sx, int sy) {
    
    que.push({sx, sy});
    while (!que.empty()) {
        
        pii tmp = que.front(); que.pop();
        int i = tmp.X, j = tmp.Y;
        
        vis[i][j] = true;
        cmpnum[i][j] = cmpcnt;
        cmpv[cmpcnt]++;
        bfsst[cmpcnt] = tmp;
        
        for (pii p : vpii{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
            
            if (i+p.X < 0 || i+p.X >= hgt || j+p.Y < 0 || j+p.Y >= wid) continue;
            if (!vis[i+p.X][j+p.Y]) {que.push({i+p.X, j+p.Y}); vis[i+p.X][j+p.Y] = true;}
            
        }
        
    }
    
}

int cnt = 0;
void lbfs(int sx, int sy) {
    
    que.push({sx, sy});
    while (!que.empty()) {
        
        cnt++;
        pii tmp = que.front(); que.pop();
        int i = tmp.X, j = tmp.Y;
        bh[i][j] = false;
        
        for (int k = 0; k < dat; k++) {
            
            if (D({i, j}, lst[k]) >= unit[k]) {
                
                len[k] += D({i, j}, lst[k]);
                lst[k] = {i, j};
                
            }
            
        }
        
        for (pii p : vpii{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
            
            if (i+p.X < 0 || i+p.X >= hgt || j+p.Y < 0 || j+p.Y >= wid) continue;
            if (bh[i+p.X][j+p.Y]) {que.push({i+p.X, j+p.Y}); bh[i+p.X][j+p.Y] = false;}
            
        }
        
    }
    
}

void bgr2hsv() {
    
    for (int i = 0; i < hgt; i++)
        for (int j = 0; j < wid; j++) {
            
            tb[i][j] = (double)B[i][j]/(double)255;
            tg[i][j] = (double)G[i][j]/(double)255;
            tr[i][j] = (double)R[i][j]/(double)255;
            cmx[i][j] = max({tb[i][j], tg[i][j], tr[i][j]});
            cmn[i][j] = min({tb[i][j], tg[i][j], tr[i][j]});
            cd[i][j] = cmx[i][j] - cmn[i][j];
            
            
        }
    //HSV 변환을 위한 정규화
    
    for (int i = 0; i < hgt; i++)
        for (int j = 0; j < wid; j++) {
            
            if (tr[i][j] > tg[i][j] && tr[i][j] > tb[i][j]) {
                
                H[i][j] = fmod(60*((tg[i][j]-tb[i][j])/cd[i][j]), 360);
                
            } else if (tg[i][j] > tr[i][j] && tg[i][j] > tb[i][j]) {
                
                H[i][j] = fmod(60*((tb[i][j]-tr[i][j])/cd[i][j]), 360) + 120;
                
            } else {
                
                H[i][j] = fmod(60*((tr[i][j]-tg[i][j])/cd[i][j]), 360) + 240;
                
            }
            //색조 계산
            
            S[i][j] = (cmx[i][j] ? cd[i][j]/cmx[i][j] : 0);
            //채도 계산
            
            V[i][j] = cmx[i][j];
            //명도 계산
            
        }
    //HSV값 계산
    
}

void hsv2bgr(int i, int j) {
    
    double c = S[i][j]*V[i][j]; //색상의 강도 계산
    double x = c * (1-abs(fmod(H[i][j]/60, 2)-1)); //색상 조정값 계산
    double m = V[i][j] - c;
    
    c *= 255; x *= 255; m *= 255;
    
    if (H[i][j] < 60) {
        
        R[i][j] = c+m; G[i][j] = x+m; B[i][j] = m;
        
    } else if (H[i][j] < 120) {
        
        R[i][j] = x+m; G[i][j] = c+m; B[i][j] = m;
        
    } else if (H[i][j] < 180) {
        
        R[i][j] = m; G[i][j] = c+m; B[i][j] = x+m;
        
    } else if (H[i][j] < 240) {
        
        R[i][j] = m; G[i][j] = x+m; B[i][j] = c+m;
        
    } else if (H[i][j] < 300) {
        
        R[i][j] = x+m; G[i][j] = m; B[i][j] = c+m;
        
    } else {
        
        R[i][j] = c+m; G[i][j] = m; B[i][j] = x+m;
        
    }
    
}

void oceanext() {
    
    for (int i = 0; i < hgt; i++)
        for (int j = 0; j < wid; j++)
            if (H[i][j] >= 190 && S[i][j] >= 0.2 && V[i][j] >= 0.2 && H[i][j] <= 230 && S[i][j] <= 1 && V[i][j] <= 1)
                oc[i][j] = true;
    //바다로 인식되는 부분만 추출
    
    int sum = 0, p[5][5] = {{1, 2, 4, 2, 1}, {2, 4, 8, 4, 2}, {4, 8, 16, 8, 4}, {2, 4, 8, 4, 2}, {1, 2, 4, 2, 1}};
    for (int k = 0; k < 5; k++)
        for (int l = 0; l < 5; l++) sum += p[k][l];
    for (int i = 3; i < hgt-3; i++)
        for (int j = 3; j < wid-3; j++) {
            
            int t = 0;
            for (int k = 0; k < 5; k++)
                for (int l = 0; l < 5; l++) t += p[k][l]*(oc[i+k-1][j+l-1] ? 0 : 1);
            if (t > sum/3) oc[i][j] = false;
            else oc[i][j] = true;
            
        }
    //가우시안 블러
    
    
    for (int i = 0; i < hgt; i++)
        for (int j = 0; j < wid; j++) {
            
            if (oc[i][j]) {R[i][j] = G[i][j] = B[i][j] = 0; continue;}
            else R[i][j] = G[i][j] = B[i][j] = 255;
            
            //HSV -> BGR
            //hsv2bgr(i, j);
            
        }
    
}

void oceancanny() {
    
    //경계 추출
    int fx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}, fy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < hgt; i++) fill(vis[i], vis[i]+wid, true);
    for (int i = 1; i < hgt-1; i++)
        for (int j = 1; j < wid-1; j++) {
            
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++) {
                    
                    gx[i][j] += (oc[i+k-1][j+l-1] != oc[i][j] ? 1 : 0)*fx[k][l];
                    gy[i][j] += (oc[i+k-1][j+l-1] != oc[i][j] ? 1 : 0)*fy[k][l];
                    
                }
            g[i][j] = sqrtl(gx[i][j]*gx[i][j] + gy[i][j]*gy[i][j]);
            if (g[i][j] >= 1.0) vis[i][j] = false;
            
        }
    
    
}

void mute() {
    
    for (int i = 0; i < hgt; i++)
        for (int j = 0; j < wid; j++)
            if (!vis[i][j]) {
                
                cmpv.pb(0); bfsst.pb({0, 0});
                cmpcnt++; bfs(i, j);
                if (cmpv[cmpmx] < cmpv[cmpcnt]) cmpmx = cmpcnt;
                
            }
    //연결된 선 컴포넌트로 묶기
    
    for (int i = 0; i < hgt; i++)
        for (int j = 0; j < wid; j++)
            if (cmpnum[i][j] == cmpmx) bh[i][j] = true;
    //가장 긴 해안선만 남기기
    
    for (int i = 0; i < hgt; i++)
        for (int j = 0; j < wid; j++) {
            
            if (bh[i][j]) B[i][j] = G[i][j] = R[i][j] = 0;
            else B[i][j] = G[i][j] = R[i][j] = 255;
            
        }
    
}

int MF = 12;
string fcnt = "000", nsum = "1234567890";
int main() {
    
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0); srand(time(0));
    
    freopen("sizelist.txt", "r", stdin);
    for (int F = 0; F < MF; F++) {
        
        if (fcnt[2] == '9') {
            
            if (fcnt[1] == '9') fcnt[0] = nsum[fcnt[0]-'0'];
            fcnt[1] = nsum[fcnt[1]-'0'];
            
        }
        fcnt[2] = nsum[fcnt[2]-'0'];
        
        ifstream fin ("_rne\\imgdata_bmp\\raw_" + fcnt + ".bmp", ios::binary);
        ofstream fout1 ("_rne\\imgdata_res1\\res1_" + fcnt + ".bmp", ios::binary);
        ofstream fout2 ("_rne\\imgdata_res2\\res2_" + fcnt + ".bmp", ios::binary);
        ofstream foutf ("_rne\\finaldata\\data_" + fcnt + ".txt");
        
        cin >> hgt >> wid;
        unsigned char T;
        for (int i = 0; i < hed; i++) {fin >> T; fout1 << T; fout2 << T;}
        for (int i = 0; i < hgt; i++)
            for (int j = 0; j < wid; j++)
                fin >> B[i][j] >> G[i][j] >> R[i][j];
        //이미지 입력받기
        
        bgr2hsv(); //hsv 이용하기 위한 변환
        oceanext(); //바다만 흑색으로 구분
        
        for (int i = 0; i < hgt; i++)
            for (int j = 0; j < wid; j++)
                fout1 << B[i][j] << G[i][j] << R[i][j];
        //바다 구분한 이미지 출력
        
        oceancanny(); //모든 경계선 추출
        mute(); //경계선 중 바다 경계선 추출
        
        for (int i = 0; i < hgt; i++)
            for (int j = 0; j < wid; j++)
                fout2 << B[i][j] << G[i][j] << R[i][j];
        //해안선 구분한 이미지 출력
        
        unitset();
        for (int i = 0; i < dat; i++) lst[i] = bfsst[cmpmx];
        lbfs(bfsst[cmpmx].X, bfsst[cmpmx].Y);
        foutf << "pixel counts : " << cmpv[cmpmx] << endl;
        for (int i = 0; i < dat; i++)
            foutf << unit[i] << endl;
        foutf << endl;
        for (int i = 0; i < dat; i++)
            foutf << len[i] << endl;
        
        /*cout << endl;
        for (pii p : ans) cout << p.X << ' ' << p.Y << endl;
        cout << endl;
        for (pii p : P[cmpmx]) cout << p.X << ' ' << p.Y << endl;*/
        
    }
    
}