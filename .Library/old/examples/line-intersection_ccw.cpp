//17387. 선분 교차 2
//#line_intersection
#include <iostream>
#define ll long long
#define ld long double
using namespace std;

//(x1,y1)->(x2,y2) 벡터 기준 (x3,y3)의 위치
//두 벡터(1->2 & 1->3)의 외적을 계산하는 방식임
//1 : 반시계 방향, -1: 시계 방향, 0: 일직선
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll c = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);
    return c == 0 ? 0 : (c>0 ? 1 : -1);
}

//x1,y1-x2,y2 와 x3,y3-x4,y4 선분이 만나는지 확인
bool line_intersect_b(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    if(x1 > x2) { swap(x1, x2); swap(y1, y2); }
    if(x3 > x4) { swap(x3, x4); swap(y3, y4); }
    int ccw1 = ccw(x1, y1, x2, y2, x3, y3), ccw2 = ccw(x1, y1, x2, y2, x4, y4);
    int ccw3 = ccw(x3, y3, x4, y4, x1, y1), ccw4 = ccw(x3, y3, x4, y4, x2, y2);

    // 엇갈려서 교차하는 경우
    if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) { return true; }

    //일직선 위에 있는 경우
    else if(ccw1 == 0 && ccw2 == 0){
        //y축과 평행한 경우는 따로 처리
        if(x1 == x2) {
            if(y1 > y2) swap(y1, y2);
            if(y3 > y4) swap(y3, y4);
            if(y1 <= y4 && y3 <= y2) return true;
        }
        //일반적인 케이스
        else if(x1 <= x4 && x3 <= x2) return true;
    }

    //한 선분 위에 다른 점이 있는 경우
    else if((ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) || (ccw1 * ccw2 <= 0 && ccw3 * ccw4 == 0)) return true;

    return false;
}

//pair.first => 0 : 교차하지 않음, 1 : 한 점에서 교차, 2 : 무수히 많은 점에서 교차
//pair.second => 교점이 하나라면 교점의 좌표, 아니면 0,0
pair<int, pair<ld, ld>> line_intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    pair<ld, ld> zero(0, 0);
    if(x1 > x2) { swap(x1, x2); swap(y1, y2); }
    if(x3 > x4) { swap(x3, x4); swap(y3, y4); }
    int ccw1 = ccw(x1, y1, x2, y2, x3, y3), ccw2 = ccw(x1, y1, x2, y2, x4, y4);
    int ccw3 = ccw(x3, y3, x4, y4, x1, y1), ccw4 = ccw(x3, y3, x4, y4, x2, y2);

    // 엇갈려서 교차하는 경우
    if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) goto onepoint;

    //일직선 위에 있는 경우
    else if(ccw1 == 0 && ccw2 == 0){
        //y축과 평행한 경우는 따로 처리
        if(x1 == x2) {
            if(y1 > y2) swap(y1, y2);
            if(y3 > y4) swap(y3, y4);
            if(y1 == y4 && y3 < y1) return {1, {x1, y1} };
            else if(y2 == y3 && y1 < y3) return {1, {x2, y2} };
            else if(y1 <= y4 && y3 <= y2) return {2, zero};
        }
        //일반적인 케이스
        else if(x1 <= x4 && x3 <= x2) {
            if(x1 == x4 && x3 < x1) return {1, {x1, y1} };
            if(x2 == x3 && x1 < x3) return {1, {x2, y2} };
            return {2, zero};
        }
    }

    //한 선분 위에 다른 점이 있는 경우
    else if((ccw1 * ccw2 == 0 && ccw3 * ccw4 <= 0) || (ccw1 * ccw2 <= 0 && ccw3 * ccw4 == 0)) goto onepoint;

    return {0, zero};

    //교점 계산
    onepoint:
    long double xd1 = x1, yd1 = y1, xd2 = x2, yd2 = y2, xd3 = x3, yd3 = y3, xd4 = x4, yd4 = y4;
        if((x1==x2 || y1==y2) && (x3==x4 || y3==y4)) {
            if(x1==x2) return {1, {x1, y3} };
            else return {1, {x3, y1} };
        } else if(x1 == x2) { 
            return {1, {x1, (y4-y3) * (x1-x3) / (x4-xd3) + y3} };
        } else if(x3 == x4) {
            return {1, {x3, (y2-y1) * (x3-x1) / (x2-xd1) + y1} }; 
        } else {
            long double a1 = (y2-y1) / (x2-xd1) - (y4-y3) / (x4-xd3);
            long double a2 = y3-y1+x1*(y2-y1)/(x2-xd1)-x3*(y4-y3)/(x4-xd3);
            long double ax = a2/a1;
            long double ay = (y2-y1) * (ax-x1) / (x2-x1) + y1;
            return {1, {ax, ay} };
        }
}

int main()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cout << (line_intersect_b(x1, y1, x2, y2, x3, y3, x4, y4) ? 1 : 0);
}