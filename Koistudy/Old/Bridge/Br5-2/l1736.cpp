#include <iostream>
#include <vector>
using namespace std;
#define nul -2147012345

struct point {
    int x; int y;
};

bool isSafeInd(int y, int x, int ylen, int xlen) {
    if(y<0) return false;
    if(x<0) return false;
    if(y>=ylen) return false;
    if(x>=xlen) return false;
    return true;
}

int turnright(int a) {
    if(a==0) return 3;
    if(a==1) return 0;
    if(a==2) return 1;
    if(a==3) return 2;
    return nul;
}

int turnleft(int dir) {
    int w = 0, a = 1, s = 2, d = 3;
    if(dir==w) return a;
    if(dir==a) return s;
    if(dir==s) return d;
    if(dir==d) return w;
    return nul;
}

int turn(int dir) {
    return turnright(dir);
}

bool canforward(int y, int x, int dir, vector<vector<int>> arr, vector<point> moves, int ylen, int xlen) {
    if(!isSafeInd(y+moves[dir].y, x+moves[dir].x, ylen, xlen)) return false;
    if(arr[y+moves[dir].y][x+moves[dir].x] != nul) return false;
    return true;
}

bool canTurn(int y, int x, int dir, vector<vector<int>> arr, vector<point> moves, int ylen, int xlen) {
    int ny = y + moves[turn(dir)].y;
    int nx = x + moves[turn(dir)].x;
    //cout << "\n(canTurn->isSafeInd: " << isSafeInd(ny, nx, ylen, xlen) << ")\n";
    if(!isSafeInd(ny, nx, ylen, xlen)) return false;
    return arr[ny][nx] == nul;
}

bool move(int *yptr, int *xptr, int dir, int ylen, int xlen, vector<vector<int>> arr, vector<point> moves, int *dirptr) {
    if(canforward(*yptr, *xptr, dir, arr, moves, ylen, xlen)) {
        *yptr += moves[dir].y; *xptr += moves[dir].x; return true;
    }
    else if(canTurn(*yptr, *xptr, dir, arr, moves, ylen, xlen)) {
        *yptr += moves[turn(dir)].y;
        *xptr += moves[turn(dir)].x;
        *dirptr = turn(dir);
        return true;
    }
    //cout << "canforward: " << canforward(*yptr, *xptr, dir, arr, moves, ylen, xlen) << " | " << "canturn: " <<canTurn(*yptr, *xptr, dir, arr, moves, ylen, xlen)<< " | " << "isSafeInd: " << isSafeInd(*yptr, *xptr, ylen, xlen) << "\n";
    return false;
}

int main()
{
    int ylen, xlen; cin >> ylen >> xlen; int k = 1;
    vector<int> basevec(xlen, nul);
    vector<vector<int>> arr(ylen, basevec);
    int w = 0, a = 1, s = 2, d = 3;
    vector<point> moves = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
    int dir = s;
    int x=xlen-1, y=0;
    int cnt = ylen*xlen;
    while(true) {
        //cout << "(" << x << ", " << y << ")\n";
        arr[y][x] = cnt--;
        if(!move(&y, &x, dir, ylen, xlen, arr, moves, &dir)) break;
    }

    for(auto aa : arr) {
        for(int b : aa) cout << b << " ";
        cout << "\n";
    }
}