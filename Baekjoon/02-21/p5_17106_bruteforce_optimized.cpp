#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<bool>> &b, int recurdepth, int selectedcnt) {
    if(recurdepth != 25) {
        b[recurdepth/5][recurdepth%5] = false;
        solve(b, recurdepth+1, selectedcnt);
        b[recurdepth/5][recurdepth%5] = true;
        solve(b, recurdepth+1, selectedcnt+1);
    } else {
        if(!b[0][1]) return;
        if(b[0][3]) { if(!b[3][3]) return; }
        if(!b[0][3] && b[3][3]) return;
        if(b[1][0]) { if(b[3][0]) return; }
        if(!b[1][0] && !b[3][0]) return;        
        if(b[1][3]) { if(selectedcnt>17) return; }
        if(!b[1][3]) if(selectedcnt <= 17) return;
        if(!b[2][2]) return;
        if(b[3][0]) if(b[1][0]) return;
        if(!b[3][0] && !b[1][0]) return;
        if(!b[3][3] && b[0][3]) return;
        if(b[3][3]) if(!b[0][3]) return;
        if(b[4][0]) if(!b[4][4]) return;
        if(!b[4][0] && b[4][4]) return;
        if(b[4][1]) return;
        if(!b[4][4] && b[4][0]) return;
        if(b[4][4]) if(!b[4][0]) return;
        if(b[3][2]) {
            int y2cnt = b[0][2] + b[1][2] + b[2][2] + b[3][2] + b[4][2];
            if(y2cnt > 3) return;
        }
        if(!b[3][2]) {
            int y2cnt = b[0][2] + b[1][2] + b[2][2] + b[3][2] + b[4][2];
            if(y2cnt <= 3) return;
        }

        bool x0=0,x1=0,x2=0,x3=0,x4=0,y0=0,y1=0,y2=0,y3=0,y4=0,y5=0,z1=0,z2=0;
        if(b[0][0] && b[1][1] && b[2][2] && b[3][3] && b[4][4]) z1 = true;
        if(b[0][4] && b[1][3] && b[2][2] && b[3][1] && b[4][0]) z2 = true;
        if(b[0][0] && b[0][1] && b[0][2] && b[0][3] && b[0][4]) x0 = true;
        if(b[1][0] && b[1][1] && b[1][2] && b[1][3] && b[1][4]) x1 = true;
        if(b[2][0] && b[2][1] && b[2][2] && b[2][3] && b[2][4]) x2 = true;
        if(b[3][0] && b[3][1] && b[3][2] && b[3][3] && b[3][4]) x3 = true;
        if(b[4][0] && b[4][1] && b[4][2] && b[4][3] && b[4][4]) x4 = true;
        if(b[0][0] && b[1][0] && b[2][0] && b[3][0] && b[4][0]) y0 = true;
        if(b[0][1] && b[1][1] && b[2][1] && b[3][1] && b[4][1]) y1 = true;
        if(b[0][2] && b[1][2] && b[2][2] && b[3][2] && b[4][2]) y2 = true;
        if(b[0][3] && b[1][3] && b[2][3] && b[3][3] && b[4][3]) y3 = true;
        if(b[0][4] && b[1][4] && b[2][4] && b[3][4] && b[4][4]) y4 = true;

        if(b[0][0]) { if(z2) return; }
        if(!b[0][0] && !z2) return;
        if(b[0][1]) { if(y1 || x0) return; }
        if(b[0][2]) { if(!z1) return; }
        if(!b[0][2] && z1) return;
        if(b[0][4]) { if(!(z2 || x0 || y4)) return; }
        if(!b[0][4] && (z2 || x0 || y4)) return;        
        if(b[1][1]) {
            bool x=x0||x1||x2||x3||x4, y=y0||y1||y2||y3||y4;
            if(!(x && y && (z1 || z2))) return;
        }
        if(!b[1][1]) {
            bool x=x0||x1||x2||x3||x4, y=y0||y1||y2||y3||y4;
            if((x && y && (z1 || z2))) return;
        }
        if(b[2][3]) {
            int ycnt = y0 + y1 + y2 + y3 + y4;
            if(ycnt<2) return;
        }
        if(!b[2][3]) {
            int ycnt = y0 + y1 + y2 + y3 + y4;
            if(ycnt>=2) return;
        }
        if(b[3][1]) if((!x1) && (!y3)) return;
        if(!b[3][1] && (x1 || y3)) return;
        if(b[3][4]) if((!z1) && (!z2)) return;
        if(!b[3][4] && (z1 || z2)) return;
        if(b[4][3]) {
            int linecnt = z1 + z2 + x0 + x1 + x2 + x3 + x4 + y0 + y1 + y2 + y3 + y4;
            if(linecnt < 3) return;
        }
        if(!b[4][3]) {
            int linecnt = z1 + z2 + x0 + x1 + x2 + x3 + x4 + y0 + y1 + y2 + y3 + y4;
            if(linecnt >= 3) return;
        }


        bool part[5][5] = {0};
        if(z1) part[0][0] = part[1][1] = part[2][2] = part[3][3] = part[4][4] = true;
        if(z2) part[0][4] = part[1][3] = part[2][2] = part[3][1] = part[4][0] = true;
        if(x0) part[0][0] = part[0][1] = part[0][2] = part[0][3] = part[0][4] = true;
        if(x1) part[1][0] = part[1][1] = part[1][2] = part[1][3] = part[1][4] = true;
        if(x2) part[2][0] = part[2][1] = part[2][2] = part[2][3] = part[2][4] = true;
        if(x3) part[3][0] = part[3][1] = part[3][2] = part[3][3] = part[3][4] = true;
        if(x4) part[4][0] = part[4][1] = part[4][2] = part[4][3] = part[4][4] = true;
        if(y0) part[0][0] = part[1][0] = part[2][0] = part[3][0] = part[4][0] = true;
        if(y1) part[0][1] = part[1][1] = part[2][1] = part[3][1] = part[4][1] = true;
        if(y2) part[0][2] = part[1][2] = part[2][2] = part[3][2] = part[4][2] = true;
        if(y3) part[0][3] = part[1][3] = part[2][3] = part[3][3] = part[4][3] = true;
        if(y4) part[0][4] = part[1][4] = part[2][4] = part[3][4] = part[4][4] = true;

        if(b[2][0]) { if(!part[2][0]) return; }
        if(b[2][2]) { if(!part[2][2]) return; }
        int partcnt = 0;
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(part[i][j]) partcnt++;
            }
        }
        
        if(b[1][4]) { if(partcnt%2 == 1) return; }
        if(!b[1][4]) if(partcnt%2==0) return;
        if(b[2][1]) { if(selectedcnt - partcnt < 5) return; }
        if(!b[2][1] && (selectedcnt - partcnt >= 5)) return;
        if(b[2][4]) if(25 - partcnt < 10) return;
        if(!b[2][4] && (25-partcnt) >= 10) return;


        
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                cout << (b[i][j] ? '#' : '.');
            }
            cout << "\n";
        }
    }
}

int main()
{
    vector<bool> bingo1(5, false);
    vector<vector<bool>> bingo(5, bingo1);
    solve(bingo, 0, 0);
}