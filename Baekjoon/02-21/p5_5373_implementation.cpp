#include <iostream>
#include <vector>
using namespace std;

//큐빙

struct face {
    char arr[3][3];
   // 윗면 : 북쪽(뒷면쪽)이 U
   // 옆면 : 윗면쪽이 U
   // 뒷면 : 북쪽이 U
   // LR은 보는 방향 기준
    face(){}
    face(char c) {
        for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            arr[i][j] = c;
    }
    void turn_cw(){
        char arrt[3][3];
        for(int i=2; i>=0; i--) {
            for(int j=0; j<3; j++) {
                arrt[j][2-i] = arr[i][j];
            }
        }
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) 
                arr[i][j] = arrt[i][j];
        }
    }
    vector<char> get(char dir) {
        vector<char> ret(3, ' ');
        switch(dir) {
            case 'U':
                ret[0] = arr[0][0];
                ret[1] = arr[0][1];
                ret[2] = arr[0][2];
                break;
            case 'L':
                ret[0] = arr[2][0];
                ret[1] = arr[1][0];
                ret[2] = arr[0][0];
                break;
            case 'D':
                ret[0] = arr[2][2];
                ret[1] = arr[2][1];
                ret[2] = arr[2][0];
                break;
            case 'R':
                ret[0] = arr[0][2];
                ret[1] = arr[1][2];
                ret[2] = arr[2][2];
                break;
        }
        return ret;
    }
    vector<char> replace(vector<char> cs, char dir) {
        return replace(cs[0], cs[1], cs[2], dir);
    }
    vector<char> replace(char c1, char c2, char c3, char dir){
        vector<char> ret = get(dir);
        switch(dir) {
            case 'U':
                arr[0][0] = c1;
                arr[0][1] = c2;
                arr[0][2] = c3;
                break;
            case 'L':
                arr[2][0] = c1;
                arr[1][0] = c2;
                arr[0][0] = c3;
                break;
            case 'D':
                arr[2][2] = c1;
                arr[2][1] = c2;
                arr[2][0] = c3;
                break;
            case 'R':
                arr[0][2] = c1;
                arr[1][2] = c2;
                arr[2][2] = c3;
                break;
        }
        return ret;
    }
};
struct cube {
    face up, down, front, back, left, right;
    cube(){
        face uf('w'), df('y'), ff('r'), bf('o'), lf('g'), rf('b');
        up = uf;
        down = df;
        front = ff;
        back = bf;
        left = lf;
        right = rf;
    }
    void turn(string action) {
        bool clockwise = (action[1]=='+');
        int time = 1;
        if(!clockwise) time = 3;
        for(int i=0; i<time; i++) turnface_cw(action[0]);
    }
    void turnface_cw(char facec) {
        face *f1, *f2, *f3, *f4, *mainf;
        char dir1, dir2, dir3, dir4;
        switch(facec) {
            case 'U':
                f1 = &back; dir1 = 'U';
                f2 = &right; dir2 = 'U';
                f3 = &front; dir3 = 'U';
                f4 = &left; dir4 = 'U';
                mainf = &up;
                break;
            case 'L':
                f1 = &up; dir1 = 'L';
                f2 = &front; dir2 = 'L';
                f3 = &down; dir3 = 'R';
                f4 = &back; dir4 = 'R';
                mainf = &left;
                break;
            case 'F':
                f1 = &up; dir1 = 'D';
                f2 = &right; dir2 = 'L';
                f3 = &down; dir3 = 'D';
                f4 = &left; dir4 = 'R';
                mainf = &front;
                break;
            case 'R':
                f1 = &up; dir1 = 'R';
                f2 = &back; dir2 = 'L';
                f3 = &down; dir3 = 'L';
                f4 = &front; dir4 = 'R';
                mainf = &right;
                break;
            case 'B':
                f1 = &up; dir1 = 'U';
                f2 = &left; dir2 = 'L';
                f3 = &down; dir3 = 'U';
                f4 = &right; dir4 = 'R';
                mainf = &back;
                break;
            case 'D':
                f1 = &back; dir1 = 'D';
                f2 = &left; dir2 = 'D';
                f3 = &front; dir3 = 'D';
                f4 = &right; dir4 = 'D';
                mainf = &down;
                break;
        }

        (*mainf).turn_cw();
        vector<char> f1s = (*f1).get(dir1);
        vector<char> f2s = (*f2).replace(f1s, dir2);
        vector<char> f3s = (*f3).replace(f2s, dir3);
        vector<char> f4s = (*f4).replace(f3s, dir4);
        (*f1).replace(f4s, dir1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int casen;
    cin >> casen;
    for(int casni = 0; casni < casen; casni++) {
        cube cube;
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            string ac; cin >> ac;
            cube.turn(ac);
        }
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cout << cube.up.arr[i][j];
            }
            cout << "\n";
        }
    }
}
