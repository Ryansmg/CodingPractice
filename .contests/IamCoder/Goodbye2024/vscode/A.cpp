#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define ppii pair<pi, pi>

LL N, M;
LL a[600000];

struct pi
{
    double x, y;
} R[600000], B[600000];

pi operator - (pi a, pi b)
{
    return pi{a.x - b.x, a.y - b.y};
}

LL ccw(pi A, pi B, pi C)
{
    double ret = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);

    if(abs(ret) < 1e-9) return 0;
    else if(ret > 0) return 1;
    else return -1;
}

LL CCW(pi A, pi B)
{
    double ret = A.x * B.y - A.y * B.x;

    if(abs(ret) < 1e-9) return 0;
    else if(ret > 0) return 1;
    else return -1;
}

pi Cross(ppii& A, ppii& B)
{
    auto& [A1, A2] = A;
    auto& [B1, B2] = B;

    double x11 = A1.x, y11 = A1.y;
    double x12 = A2.x, y12 = A2.y;
    double x21 = B1.x, y21 = B1.x;
    double x22 = B2.x, y22 = B2.x;
    double dx1 = x12 - x11, dy1 = y12 - y11;
    double dx2 = x22 - x21, dy2 = y22 - y21;

    double r1 = dx1 * dy2 - dy1 * dx2;
    double r2 = dy2 * (x21 - x11) - dx2 * (y21 - y11);

    double t = r2 / r1;

    pi ret;
    ret.x = x11 + t * dx1;
    ret.y = y11 + t * dy1;

    return ret;
}

bool PIP(pi P)
{
    if(ccw(R[0], R[1], P) < 0 || ccw(R[0], R[N - 1], P) > 0) return false;

    LL s = 1, e = M - 2, m;
    while(s < e)
    {
        m = (s + e + 1) / 2;
        if(ccw(R[0], R[m], P) <= 0) s = m;
        else e = m - 1;
    }
    return ccw(R[s], R[s + 1], P) >= 0;
}

bool in(LL i, LL j)
{
    pi dI;
    dI.x = B[(i + 1) % M].x - B[i].x;
    dI.y = B[(i + 1) % M].y - B[i].y;
    pi dJ;
    dJ.x = B[(j + 1) % M].x - B[j].x;
    dJ.y = B[(j + 1) % M].y - B[j].y;

    if(CCW(dI, dJ) >= 0) return false;

    pi P = Cross({B[i], B[(i + 1) % M]}, {B[j], B[(j + 1) % M]});
    return PIP(P);
}

void roll(LL i, LL j)
{
    if(in(i, j)) roll(i, (j + 1) % M);
    else
    {
        a[i] = (j - i + M) % M;

        if(i == M - 1) return;
        if((j - i + M) % M == 2) roll((i + 1) % M, (i + 1) % M);
        else roll((i + 1) % M, (j + 1) % M);
    }
}

int main()
{
    scanf("%lld %lld", &N, &M);
    for(LL i = 0; i < N; i++) scanf("%lld %lld", &R[i].x, &R[i].y);
    R[N].x = R[0].x;
    R[N].y = R[0].y;
    for(LL i = 0; i < M; i++) scanf("%lld %lld", &B[i].x, &B[i].y);

    roll(1, 3);

    for(LL i = 0; i < M; i++) scanf("%lld ", a[i]);

    return 0;
}