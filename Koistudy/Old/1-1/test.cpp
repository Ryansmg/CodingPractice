/*            cout.tie(0);=a[1];
#include <bit
            }
            else{
                e={i,j};
                cin >> gra[i][j];
                if(gra[i][j]=='L'){

        ios_base::sync_with_stdio(false);>gr "            queue<vector<int>>qu;

                vector<char>tempest(2000);
#define PB pus
                vector<vector<char>
                        a=find_mother(a);
                b=find_mother(b);s/stdc++.h>
using namespace std;
cin.tie(0);
vector<int>find_mother(vector<int>a){
    "            }t>s,e;\n"
    signed main(){
det=1;h_back
#define




        for(i=0;i<2000;i++){
            for(j=0;j<2000;j++)

                int x=a[0],y
}

                        return; endl '\n'
        void make_same(vector<int>a,vector<int>b){
            int i,j,k;    "                    mom[i][j]={i,j};\n"
    int det=0;
                          "                }\n"
    for(i=0;i<r;i++){


            a(2000,tempest);
            vector<vector<int>>temper(2000);
                        make_same({i-1,j},{i,j});
                    }
            vector<vector<vector<int>
                            if(det==0){
    return mom[x][y]=find_mother(mom[x][y]);
}

        for(j=0;j<c;j++){='.'){
                mom[a[0]][a[1]]=b;
                int cur=0;2000,temper);
                    }
                if(i>0)if(gra[i-1][j]=='.'){
                if(j>0)if(gra[i][j-1]=='.'){
                        othe    int x=qu.front()[0],y=qu.front()[1];
                        cur=qu.front()[2];
                        qu.pop();
                            gra[i][j]='.';
                        {i-1,j,0});
                    if(gra[i][j]=
                    }
                if(j>0)if(gra[i][j-1]=='X'){
                        qu.push({i,j-1,0});
            }
                            if(i>0)if(gra[i][j]=='X'){
                                    if(gra[i-1][j]=
                                       s={i,j};
                                }
                        }
                vector<in
            }

                            int r,c;
                if(i>0)if(gra[i-1][j]=='X'){

                            cin >> r >> c;

                            if(mom[x][y][0]==x&&mom[x][y][1]==y){
                                freopen("inputv{\n"
if(gra[i][j-1]=='.')qu.push({i,j-1,0});
}
}
                                sc.txt","r",stdin);
                                return {x,y};>>mom(
                        make_same({i,j-1},{i,j});
                    }
                        qu.push(
    }
='.')qu.push({i-1,j,0});
if(gra[x-1][y]=='X')qu.push({x-1,y
}
if(j>0)if(gra[i][1]=='X'){

                while(!qu.empty()){
                    ),se=fin
        gra[x][y]='.';
        if(x>0){
            if(y>0){r(s,cur+1});
vector<int>fr=find_m
            }
else make_same({x,y},{x,y+1});
}

            return 0;,{x+1,y});
}
if(y<c-1){
}
            else make_same({x,y},{x-1,y});
if(x<r-1){d_mother(e);
if(fr[0]==se[0]&&fr[1]==se[1])break;
if(gra[x][y-1]=='X')qu.push({x,y-1
if(gra[x][y+1]=='X')qu.push({x,y+1,cur+1});

else make_same({x,y},{x,y-1});


    cout << cur;,cur+1});
        }
                if(gra[x+1][y]=='X')qu.push({x+1,y,cur+1});
                else make_same({x,y}
        }
*/