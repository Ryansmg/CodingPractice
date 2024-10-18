#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1708. 볼록 껍질
// #볼록 껍질

#define int long long

//(x1,y1)->(x2,y2) 벡터 기준 (x3,y3)의 위치
// 1이 반시계 방향
int _ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int c = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);
    return c == 0 ? 0 : (c>0 ? 1 : -1);
}

struct point {
    int x, y;
    bool operator< (const point &a) {
        return y == a.y ? x < a.x : y < a.y;
    }
    point(){}
    point(int a, int b) : x(a), y(b) {}
};
int ccw(point &a, point &b, point &c) {
    return _ccw(a.x, a.y, b.x, b.y, c.x, c.y);
}
int sqdist(point &a, point &b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

point constP;

bool cmp(point &a, point &b) {
    int c = ccw(constP, a, b);
    return c==0 ? sqdist(constP,a)<sqdist(constP,b) : c>0;
}

int input() { int i; cin >> i; return i; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n = input();
    vector<point> points;
    for(int i=0; i<n; i++) points.emplace_back(input(), input());

    //y좌표로 정렬 => 기준점 설정
    sort(points.begin(), points.end());
    constP = points[0];

    //반시계 방향으로 정렬
    sort(points.begin(), points.end(), cmp);

    //구성하는 점 스택에 넣기
    vector<point> stack; int size = 2;
    stack.push_back(points[0]); stack.push_back(points[1]);
    for(int i=2; i<n; i++) {
        while(size>=2 && ccw(stack[size-2], stack[size-1], points[i])<=0) {
            stack.pop_back();
            size--;
        }
        stack.push_back(points[i]);
        size++;
    }
    cout << size;
}
