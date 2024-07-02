//17387. 선분 교차 2
//17386. 선분 교차 1
//#line_intersection
#include <iostream>
#define ll long long
using namespace std;

//(x1,y1)->(x2,y2) 벡터 기준 (x3,y3)의 위치
//두 벡터의 외적을 계산하는 방식임
//1 : 반시계 방향, -1: 시계 방향, 0: 일직선
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll c = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);
    return c == 0 ? 0 : (c>0 ? 1 : -1);
}

int main()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if(x1 > x2) { swap(x1, x2); swap(y1, y2); }
    if(x3 > x4) { swap(x3, x4); swap(y3, y4); }
    int ccw1 = ccw(x1, y1, x2, y2, x3, y3), ccw2 = ccw(x1, y1, x2, y2, x4, y4);
    if(ccw1 * ccw2 > 0) { cout << 0; return 0; }
    if(ccw1 == 0 && (x1 - x3) * (x3 - x2) >= 0 && (y1 - y3) * (y3 - y2) >= 0) { cout << 1; return 0; }
    if(ccw2 == 0 && (x1 - x4) * (x4 - x2) >= 0 && (y1 - y4) * (y4 - y2) >= 0) { cout << 1; return 0; }
    int ccw3 = ccw(x3, y3, x4, y4, x1, y1), ccw4 = ccw(x3, y3, x4, y4, x2, y2);
    if(ccw3 * ccw4 > 0) { cout << 0; return 0; }
    if(ccw3 * ccw4 < 0) { cout << 1; return 0; }
    if(ccw3 == 0 && (x3 - x1) * (x1 - x4) >= 0 && (y3 - y1) * (y1 - y4) >= 0) { cout << 1; return 0; }
    if(ccw4 == 0 && (x3 - x2) * (x2 - x4) >= 0 && (y3 - y2) * (y2 - y4) >= 0) { cout << 1; return 0; }
    cout << 0; return 0;
}