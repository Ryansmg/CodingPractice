#include <iostream>
#include <vector>
using namespace std;

// 1708. 볼록 껍질
// #볼록 껍질

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int c = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);
    return c == 0 ? 0 : (c>0 ? 1 : -1);
}

int main()
{
    
}
