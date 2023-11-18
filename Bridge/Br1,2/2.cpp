#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define lint long long

int main()
{
    int board[10][10];
    for(int i=0; i<10; i++)
    for(int j=0; j<10; j++)
    cin >> board[i][j];
    int x=1, y=1;
    while(true){
        if(board[y][x]==2) {board[y][x]=9;break;}
        board[y][x]=9;
        if(x==8&&y==8) break;
        if(board[y][x+1]!=1) x++;
        else if(board[y+1][x]!=1) y++;
        else break;
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}