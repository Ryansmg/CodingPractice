#include <bits/stdc++.h>
#pragma region macros
#define GCC_OPTIMIZE_ENABLE false

using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#define int long long
#define double long double
#define cint const int &

#define llmax 9223372036854775807 // 2^63-1
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)

#define pass {cout << "";} // do nothing
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)

template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

#ifndef int
#define intmax 2147483647
#else
#define intmax llmax
#endif

#pragma region lint
#define lint __int128
#define ll long long
lint LINTMAX = ((lint(1)<<126)-1)*2+1;
string lint2str(const lint &i) {string ret,bs;if(i==-LINTMAX-1)return lint2str(i/10)+"8";if(!i)return "0";if(i<0)return "-"+lint2str(-i);
	lint t=1; forn(as, 18)t*=10;lint a=i/(t*t);if(a){ret += to_string((ll) a);bs = to_string((ll) (i / t % (t * 10) + t));
		forn(j, 18) ret += bs[j + 1];bs = to_string((ll) ((i % t) + t));forn(j, 18) ret += bs[j + 1];
	} else {lint b = i / t % (t * 10);if (b) {ret += to_string((ll) b);bs = to_string((ll) ((i % t) + t));
			forn(j, 18) ret += bs[j + 1];} else { ret += to_string((ll) (i % t)); }}return ret;}
istream &operator>>(istream &in, lint &l) {string s;in>>s;lint t=l=0,size=s.size(),k=1;if(s[0]=='-')t=1;
	for(lint i=size-1;i>=t;i--){if(!t)l+=(s[i]-'0')*k;else l-=(s[i]-'0')*k;k*=10;}return in;}
ostream &operator<<(ostream &out,const lint &i){ out << lint2str(i); return out; }
#pragma endregion

template <typename T = int> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#pragma endregion

// 30043. Binding of Isaac
// #implementation #bfs #case_work #bitmasking #backtracking

const static int None=-1, Start=0, Normal=1, Boss=2, Secret=3, Treasure=4,
        Shop=5, Devil=6, Angel=7, Sacrifice=8, Curse=9;
const static char pr[] = {'R', 'a', 'B', 'X', 'T', 'M', 'D', 'A', 'S', 'C'};

class Room {
public:
    int type=-1, val=0, row=-1, column=-1;
    Room()=default;
    explicit Room(int Type, int r, int c) : type(Type), row(r), column(c) {}
};

class Player {
public:
    int hp=6, atk=1, coin=0, bomb=3, r=4, c=4;
    v2<bool> vis = v2<bool>(9, v<bool>(9, false));
    v2<bool> bfsVis = v2<bool>(9, v<bool>(9, false));
    v2<bool> dontVisit = v2<bool>(9, v<bool>(9, false));
    Player()=default;
//    Player(int HP, int ATK, int COIN, int BOMB, int R, int C) : hp(HP), atk(ATK), coin(COIN), bomb(BOMB), r(R), c(C) {}
    Player(const Player &pre, int _hp, int _atk, int _coin, int _bomb, int _r, int _c, bool resetBfsVis = false) {
        hp = pre.hp + _hp;
        atk = pre.atk + _atk;
        coin = pre.coin + _coin;
        bomb = pre.bomb + _bomb;
        r = pre.r + _r;
        c = pre.c + _c;
        vis = pre.vis;
        dontVisit = pre.dontVisit;
        if(resetBfsVis) bfsVis = v2<bool>(9, v<bool>(9, false));
        else bfsVis = pre.bfsVis;
        bfsVis[r][c] = true;
        assert(coin>=0 && bomb>=0);
    }
};

string seedStr;
int S;
int rand_call = 0;
const int a=1103515245, c_=12345, m=2147483648;
int rand_() {
    if(!rand_call++) return S;
    return S=(a*S+c_)%m;
}
int randInt(int l, int r) { return l + (rand_() % (r-l+1)); }
bool chance(int p) { return randInt(1, 100) <= p; }
template <typename T> T& choice(v<T> arr) { return arr[randInt(0, arr.size()-1)]; }
int choice_idx(int size) { return randInt(0, size-1); }

v2<Room> board(9, v<Room>(9, Room()));

class Point {
public: int row, column;
    Point(int r, int c) : row(r), column(c){}
    Room& operator()() const { return board[row][column]; }
    [[nodiscard]] bool inBound() const {
        if(row<0 || column<0 || row>=9 || column>=9) return false;
        return true;
    }
};

bool Log2 = false, Log3 = false;
#define log2 if(Log2) cout
#define log3 if(Log3) cout

auto inBound = [](int r, int c) -> bool
{ if(r<0||c<0||r>=9||c>=9) return false; return true; };

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};
int calc_adj(cint row, cint column) {
    int ret = 0;
    forn(i, 4) {
        int nr = row+dr[i], nc=column+dc[i];
        if(!inBound(nr, nc)) continue;
        if(board[nr][nc].type != -1) ret++;
    }
    return ret;
};

signed main() {
    cin >> seedStr;
    // S1 생성
    S = [](string seed) -> int {
        seed.erase(4,1); int ret = 0;
        forn(i, 8) {
            ret *= 36;
            if('0'<=seed[i]&&seed[i]<='9') ret += seed[i]-'0';
            else ret += seed[i]-'A'+10;
        }
        return ret % m;
    }(seedStr);

    auto chk_adj_start = [&](cint row, cint column) {
        forn(i, 4) {
            int nr = row+dr[i], nc=column+dc[i];
            if(!inBound(nr, nc)) continue;
            if(board[nr][nc].type == Start) return true;
        }
        return false;
    };

    // 던전 생성
    // 1단계
    int N = randInt(10, 20);
    log2 << "N: " << N << '\n';

    // 2단계
    log2 << "room_gen_2" << '\n';
    v<Point> room;
    board[4][4].type = Start;
    board[4][4].row = board[4][4].column = 4;
    room.emplace_back(4, 4);
    int room_gen_cnt = 0;

    while(true) {
        if(room_gen_cnt == N) break;
        queue<Point> Q;
        Q.push(choice(room));
        while(!Q.empty()) {
            Point fr = Q.front(); Q.pop();
            log2 << "front: " << fr.row << ", " << fr.column << '\n';
            forn(idr, 4) {
                if(room_gen_cnt == N) break;
                int nr = fr.row+dr[idr], nc=fr.column+dc[idr];
                if(!inBound(nr, nc)) {
                    log2 << "OutOfBound " << nr << ", " << nc << '\n';
                    continue;
                }
                if(board[nr][nc].type != -1) {
                    log2 << "room_already_exist " << nr << ", " << nc << '\n';
                    continue;
                }
                if(calc_adj(nr, nc)>=2) {
                    log2 << "too_many_adj " << nr << ", " << nc << '\n';
                    continue;
                }
                if(!chance(50)) {
                    log2 << "chance_fail " << nr << ", " << nc << '\n';
                    continue;
                }
                log2 << "gen: " << nr << ", " << nc << '\n';
                Room gen(Normal, nr, nc);
                Q.emplace(gen.row, gen.column);
                room.emplace_back(gen.row, gen.column);
                board[nr][nc] = gen;
                room_gen_cnt++;
            }
            if(room_gen_cnt == N) break;
        }
    }
    assert((*room.begin())().type == Start);
    room.erase(room.begin());

    // 3단계
    v<Point> special, notSpecial;
    for(const Point &r : room)
        if(calc_adj(r.row, r.column)==1) special.push_back(r);
        else notSpecial.push_back(r);
    // 일반방 지정
    v<int> require;
    forf(i, 0, 9) forn(j, 10-i) require.push_back(i);
    log2 << "require: "; for(int i : require) log2 << i << ' '; log2 << '\n';
    log3 << "일반방" << '\n';
    for(Point &r : notSpecial) {
        r().type = Normal;
        r().val = choice(require);
        log3 << r.row << "," << r.column << "->" << r().val << endl;
    }
    // 보스방 지정
    log3 << "보스방" << '\n';
    v<Point> boss;
    for(Point &r : special)
        if(!chk_adj_start(r.row, r.column)) boss.push_back(r);
    int boss_idx = choice_idx((int)boss.size());
    boss[boss_idx]().type = Boss;
    Point boss_room = boss[boss_idx];
    log3 << "boss_room = " << boss_room.row << ' ' << boss_room.column << '\n';
    int special_cnt = (int) special.size();
    forn(i, special_cnt) {
        if(special[i]().type == Boss) {
            special.erase(special.begin()+i);
            break;
        }
        if(i==special_cnt-1) assert(false);
    }
    if(Log3) {
        for(auto p : special) assert(p().type != Boss);
    }
    // 비밀방 지정 시도
    if(!special.empty()) {
        int idx = choice_idx((int)special.size());
        special[idx]().type = Secret;
        special.erase(special.begin()+idx);
    }
    // 보물방 지정 시도
    if(!special.empty()) {
        int idx = choice_idx((int)special.size());
        special[idx]().type = Treasure;
        special.erase(special.begin()+idx);
    }
    if(!special.empty() && N>=15 && chance(25)) {
        int idx = choice_idx((int)special.size());
        special[idx]().type = Treasure;
        special.erase(special.begin()+idx);
    }
    // 상점방 지정 시도
    if(!special.empty()) {
        if(N <= 15 || chance(66)) {
            int idx = choice_idx((int)special.size());
            special[idx]().type = Shop;
            special.erase(special.begin()+idx);
        }
    }
    // 악마방 / 천사방 생성 시도
    const int dr2[] = {0, 0, 1, -1};
    const int dc2[] = {1, -1, 0, 0};
    int xm=4, ym=4, xM=4, yM=4;
    for(Point &p : room) {
        xm = min(xm, p.row);
        xM = max(xM, p.row);
        ym = min(ym, p.column);
        yM = max(yM, p.column);
    }
    bool gen_devil = false;
    bool gen_angel = false;
    if(chance(20)) {
        v<Point> reward;
        forn(i, 4) {
            Point t(boss_room.row + dr2[i], boss_room.column + dc2[i]);
            if(!t.inBound()) continue;
            if(t().type != -1) continue;
            if(!(xm <= t.row && t.row <= xM) || !(ym <= t.column && t.column <= yM)) continue;
            reward.push_back(t);
        }
        Point chosen = choice(reward);
        if(chance(50)) {
            chosen().type = Devil;
            gen_devil = true;
        }
        else {
            chosen().type = Angel;
            gen_angel = true;
        }
    }

    // 희생방 지정 시도
    if(!special.empty()) {
        if(gen_angel || chance(14)) {
            int idx = choice_idx(special.size());
            special[idx]().type = Sacrifice;
            special.erase(special.begin() + idx);
        }
    }

    // 저주방 지정 시도
    if(!special.empty() && gen_devil && chance(50)) {
        int idx = choice_idx(special.size());
        special[idx]().type = Curse;
        special.erase(special.begin() + idx);
    }

    // 일반방 추가 지정
    for(auto &p : special) {
        p().type = Normal;
        p().val = choice(require);
    }

    // BFS를 통한 승리 여부 탐색
    bool win = false; int bfsCnt = 0;
    stack<Player> search;
    Player temp; temp.vis[4][4] = true; temp.bfsVis[4][4] = true;
    search.push(temp);
    while(!search.empty()) {
        Player now = search.top(); search.pop();
        bfsCnt++;
//        cout << now.r << ' ' << now.c << endl;
        if(now.vis[now.r][now.c]) {
            if(board[now.r][now.c].type == Shop && now.coin>1) {
                int buyCnt = now.coin/2;
                forf(i, 0, buyCnt) {
                    search.emplace(now, i, buyCnt-i, -buyCnt*2, 0, 0, 0, false);
                }
                continue;
            }
            forn(dir, 4) {
                int nr = now.r + dr[dir], nc = now.c + dc[dir];
                if(!inBound(nr, nc)) continue;
                if(now.bfsVis[nr][nc]) continue;
                if(now.dontVisit[nr][nc]) continue;
                if(board[nr][nc].type == None) continue;
                if(board[nr][nc].type == Devil) continue;
                if(board[nr][nc].type == Angel) continue;
                pass
                search.emplace(now, 0, 0, 0, 0, dr[dir], dc[dir]);
            }
            continue;
        }
        now.vis[now.r][now.c] = true;
        now.bfsVis[now.r][now.c] = true;
        int cad = calc_adj(now.r, now.c);
        if(cad == 1) now.dontVisit[now.r][now.c] = true;
        else {
            int adjVis = 0;
            forn(i, 4) {
                int nr = now.r + dr[i], nc = now.c + dc[i];
                if (!inBound(nr, nc)) continue;
                if (board[nr][nc].type == None) continue;
                if (board[nr][nc].type == Devil) continue;
                if (board[nr][nc].type == Angel) continue;
                if (now.dontVisit[nr][nc]) continue;
                adjVis++;
            }
            assert(adjVis > 0);
            if (adjVis == 1) now.dontVisit[now.r][now.c] = true;
        }

        if(board[now.r][now.c].type == Normal) {
            if(board[now.r][now.c].val <= now.atk) {
                search.emplace(now, 0, 0, 1, 0, 0, 0, true);
            } else {
                if(now.bomb>0) search.emplace(now, 0, 0, 1, -1, 0, 0, true);
                if(now.hp>1) search.emplace(now, -1, 0, 1, 0, 0, 0, true);
            }
        }
        else if(board[now.r][now.c].type == Boss) {
            if (now.atk >= 10) {
                win = true;
                break;
            }
        }
        else if(board[now.r][now.c].type == Secret) {
            if(now.bomb>0) search.emplace(now, 2, 2, 2, -1, 0, 0, true);
        }
        else if(board[now.r][now.c].type == Treasure)
            search.emplace(now, 0, 1, 0, 0, 0, 0, true);
        else if(board[now.r][now.c].type == Shop)
            search.push(now);
        else if(board[now.r][now.c].type == Sacrifice){
            if(now.hp>2) search.emplace(now, -2, 3, 0, 0, 0, 0, true);
        }
        else if(board[now.r][now.c].type == Curse)
            search.emplace(now, 0, -2, 3, 1, 0, 0, true);
        else assert(false);
    }
    cout << (win?"CLEAR\n":"GAME OVER\n");

    // 던전 출력
    // H, W 계산
    xm = xM = ym = yM = 4;
    forn(r, 9) forn(c, 9) {
        if(board[r][c].type == -1) continue;
        xm = min(xm, r);
        xM = max(xM, r);
        ym = min(ym, c);
        yM = max(yM, c);
    }
    int H = xM-xm+1, W=yM-ym+1;
    int dgh = 6*H+3, dgw = 6*W+3;
    v2<char> dungeon(dgh, v<char>(dgw, ' '));
    // ##########
    forn(i, dgw) dungeon[0][i] = dungeon[dgh-1][i] = '#';
    forn(i, dgh) dungeon[i][0] = dungeon[i][dgw-1] = '#';
    auto getCoord = [&](const int &r, const int &c) -> ii {
        int nr = r-xm, nc = c-ym;
        return {4 + 6*nr, 4+6*nc};
    };
    forn(r, 9) forn(c, 9) {
        if(board[r][c].type == None) continue;
        ii coord = getCoord(r, c);
        if(board[r][c].type == Normal) dungeon[coord[0]][coord[1]] = (char)('0'+board[r][c].val);
        else dungeon[coord[0]][coord[1]] = pr[board[r][c].type];
        const int Dr[] = {-2, -2, -2, -2, -2, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1};
        const int Dc[] = {-2, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2};
        const char Dch[] = {'+', '-', '-', '-', '+', '|', '|', '|', '+', '-', '-', '-', '+', '|', '|', '|'};
        const char Dad[] = {'/', '^', '^', '^', '\\', '>', '>', '>', '/', 'v', 'v', 'v', '\\', '<', '<', '<'};
        forn(i, 16) {
            if(dungeon[coord[0]+Dr[i]][coord[1]+Dc[i]]!=' ') continue;
            if(board[r][c].type == Start || board[r][c].type == Boss)
                dungeon[coord[0]+Dr[i]][coord[1]+Dc[i]] = '@';
            else if(board[r][c].type == Angel || board[r][c].type == Devil)
                dungeon[coord[0]+Dr[i]][coord[1]+Dc[i]] = Dad[i];
            else dungeon[coord[0]+Dr[i]][coord[1]+Dc[i]] = Dch[i];
        }
        int nr = r+1, nc = c;
        ii crd2 = getCoord(nr, nc);
        while(true) {
            if(!inBound(nr, nc)) break;
            if(board[r][c].type == Secret) break;
            if(board[r][c].type == Devil) break;
            if(board[r][c].type == Angel) break;
            if(board[nr][nc].type == Secret) break;
            if(board[nr][nc].type == Devil) break;
            if(board[nr][nc].type == Angel) break;
            if(board[nr][nc].type == None) break;
            int nnr = (coord[0] + crd2[0])/2;
            int nnc = (coord[1] + crd2[1])/2;
            dungeon[nnr][nnc-1] = dungeon[nnr][nnc+1] = '|';
            if(board[r][c].type != Start && board[r][c].type != Boss) {
                dungeon[nnr-1][nnc-1] = dungeon[nnr-1][nnc+1] = '+';
            }
            dungeon[nnr-1][nnc] = dungeon[nnr+1][nnc] = ';';
            if(board[nr][nc].type != Start && board[nr][nc].type != Boss) {
                dungeon[nnr+1][nnc-1] = dungeon[nnr+1][nnc+1] = '+';
            }
            break;
        }
        nr = r, nc = c+1;
        crd2 = getCoord(nr, nc);
        while(true) {
            if(!inBound(nr, nc)) break;
            if(board[r][c].type == Secret) break;
            if(board[r][c].type == Devil) break;
            if(board[r][c].type == Angel) break;
            if(board[nr][nc].type == Secret) break;
            if(board[nr][nc].type == Devil) break;
            if(board[nr][nc].type == Angel) break;
            if(board[nr][nc].type == None) break;
            int nnr = (coord[0] + crd2[0])/2;
            int nnc = (coord[1] + crd2[1])/2;
            dungeon[nnr-1][nnc] = dungeon[nnr+1][nnc] = '-';
            if(board[r][c].type != Start && board[r][c].type != Boss) {
                dungeon[nnr-1][nnc-1] = dungeon[nnr+1][nnc-1] = '+';
            }
            dungeon[nnr][nnc-1] = dungeon[nnr][nnc+1] = ';';
            if(board[nr][nc].type != Start && board[nr][nc].type != Boss) {
                dungeon[nnr+1][nnc+1] = dungeon[nnr-1][nnc+1] = '+';
            }
            break;
        }
    }

    fastio;
    for(const auto& arr : dungeon) {
        for(const char &c : arr) cout << (c==';'?' ':c);
        cout << '\n';
    }
}
