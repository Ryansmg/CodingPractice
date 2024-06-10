#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t; cin >> t;
    for(int ti = 0; ti<t; ti++) {
        int h, m;
        bool ispm = false;
        scanf(" %d:%d", &h, &m);
        if(h>=12) {
            ispm=true;
            h-=12;
        }
        if(h==0)h+=12;
        printf("%02d:%02d %s\n", h, m, ispm?"PM":"AM");
    }
}