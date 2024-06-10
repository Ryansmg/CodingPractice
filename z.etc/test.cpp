//
// Created by น่นฮย๙ on 2024-06-06.
//
#include <bits/stdc++.h>
#define forf(i, s, e) for(int i = s; i <= e; i++)
#define int long long
#define all(V) V.begin(), V.end()
#define pb push_back
#define compress(v) v.erase(unique(all(v)), v.end())
#define idx(i, v) lower_bound(all(v), i) - v.begin()

using namespace std;
using pii = array<int, 2>;
using tii = array<int, 3>;
using fii = array<int, 4>;
template <typename T> using VEC = vector <T>;
const int SIZE = 3e3 + 10;
const int inf = 1e15;

VEC <tii> arr;
VEC <VEC<pii>> gold;
VEC <int> X, Y;
VEC <fii> tree(SIZE);
int N, M, res;

void reset(int node, int start, int end) {
    fill(tree.begin(), tree.end(), (fii){0, 0, 0, 0});
//    if(start == end) {
//        tree[node] = {0, 0, 0, 0}; return;
//    }
//    int mid = start + end; mid /= 2;
//    reset(node << 1, start, mid);
//    reset((node << 1) | 1, mid + 1, end);
//    tree[node] = {0, 0, 0, 0};
}

void edit(int node, int start, int end, int idx, int val) {
    if(start > idx || end < idx) return;
    fii tmp = {0, 0, 0, 0};
    if(start == end) {
        tmp = tree[node];
        tmp[0] += val; tmp[1] += val; tmp[2] += val; tmp[3] += val;
        tree[node] = tmp; return;
    }
    int mid = start + end; mid /= 2;
    edit(node << 1, start, mid, idx, val);
    edit(node << 1, mid + 1, end, idx, val);
    tmp[0] = tree[node << 1][0] + tree[node << 1 | 1][0];
    tmp[1] = max(tree[node << 1][1], tree[node << 1][0] + tree[node << 1 | 1][1]);
    tmp[2] = max(tree[node << 1 | 1][2], tree[node << 1][2] + tree[node << 1 | 1][0]);
    tmp[3] = max(max(tree[node << 1][3], tree[node << 1 | 1][3]), tree[node << 1][2] + tree[node << 1 | 1][1]);
    tree[node] = tmp;
}

fii query(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return {0, 0, 0, 0};
    if(left <= start && end <= right) return tree[node];
    int mid = start + end; mid /= 2;
    fii lf = query(node << 1, start, mid, left, right), rf = query(node << 1 | 1, mid + 1, end, left, right);
    fii tmp;
    tmp[0] = lf[0] + rf[0];
    tmp[1] = max(lf[1], lf[0] + rf[1]);
    tmp[2] = max(rf[2], lf[2] + rf[0]);
    tmp[3] = max(max(lf[3], rf[3]), lf[2] + rf[1]);
    return tmp;
}

struct one {
    struct two {
        struct three {
            struct four {
                struct five {
                    struct q {
                        struct w {
                            struct e {
                                struct r {
                                    struct t {
                                        struct y {
                                            struct u {
                                                struct i {
                                                    struct o {
                                                        struct p {
                                                            struct a {
                                                                struct s {
                                                                    struct d {
                                                                        struct f {
                                                                            struct g {
                                                                                struct h {
                                                                                    struct j {
                                                                                        struct k {
                                                                                            struct l {
                                                                                                struct z {
                                                                                                    struct x {
                                                                                                        struct c {
                                                                                                            struct v {
                                                                                                                struct b {
                                                                                                                    struct n {
                                                                                                                        struct m {
                                                                                                                            struct six {
                                                                                                                                struct seven {
                                                                                                                                    struct eight {
                                                                                                                                        struct nine {
                                                                                                                                            struct ten {
                                                                                                                                                struct apple {
                                                                                                                                                    struct apple2 {
                                                                                                                                                        struct apple3 {
                                                                                                                                                            struct apple4 {
                                                                                                                                                                struct apple5 {
                                                                                                                                                                    struct apple6 {
                                                                                                                                                                        struct apple7 {
                                                                                                                                                                            struct apple8 {
                                                                                                                                                                                struct apple9 {
                                                                                                                                                                                    struct apple10 {
                                                                                                                                                                                        struct banana1 {
                                                                                                                                                                                            struct banana {
                                                                                                                                                                                                struct bananana {
                                                                                                                                                                                                    struct banananana {
                                                                                                                                                                                                        int val;
                                                                                                                                                                                                    };
                                                                                                                                                                                                };
                                                                                                                                                                                            };
                                                                                                                                                                                        };
                                                                                                                                                                                    };
                                                                                                                                                                                };
                                                                                                                                                                            };
                                                                                                                                                                        };
                                                                                                                                                                    };
                                                                                                                                                                };
                                                                                                                                                            };
                                                                                                                                                        };
                                                                                                                                                    };
                                                                                                                                                };
                                                                                                                                            };
                                                                                                                                        };
                                                                                                                                    };
                                                                                                                                };
                                                                                                                            };
                                                                                                                        };
                                                                                                                    };
                                                                                                                };
                                                                                                            };
                                                                                                        };
                                                                                                    };
                                                                                                };
                                                                                            };
                                                                                        };
                                                                                    };
                                                                                };
                                                                            };
                                                                        };
                                                                    };
                                                                };
                                                            };
                                                        };
                                                    };
                                                };
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
};

signed main() {
    one::two::three::four::five::q::w::e::r::t::y::u::i::o::p::a::s::d::f::g::h::j::k::l::z::x::c::v::b::n::m::six::seven::eight::nine::ten::apple::apple2::apple3::apple4::apple5::apple6::apple7::apple8::apple9::apple10::banana1::banana::bananana::banananana t{};
    t.val = 0;
    cin >> N;
    forf(i, 1, N){
        int a, b, c; cin >> a >> b >> c;
        arr.pb({a, b, c});
        X.pb(a); Y.pb(b);
    }
    sort(all(X)); sort(all(Y));
    compress(X); compress(Y);
    M = Y.size();
    N = X.size();
    gold.resize(M + 1);
    for(auto i : arr){
        i[0] = idx(i[0], X) + 1;
        i[1] = idx(i[1], Y) + 1;
        gold[i[1]].pb({i[0], i[2]});
    }
    forf(i, 1, M){
        reset(1, 1, N);
        forf(j, i, M) {
            for(auto k : gold[j]) {
                edit(1, 1, N, k[0], k[1]);
                res = max(res, query(1, 1, N, 1, N)[3]);
            }
        }
    }
    cout << res << '\n';
}
