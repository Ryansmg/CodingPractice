#include <iostream>
#include <vector>
using namespace std;

//다이아몬드 광산

int main() {
    vector<vector<bool>> map;
    vector<vector<pair<int, int>>> ans; //< /, \ > down
    int maxi = 0;
    int height, width;
    cin >> height >> width;
    vector<vector<pair<int, int>>> ans2(height); //< \, / > up
    for(int i=0; i<height; i++) {
        vector<bool> temp;
        string s; cin >> s;
        for(char c : s) temp.push_back(c=='1');
        map.push_back(temp);
    }
    vector<pair<int, int>> t2;
    for(int j=0; j<width; j++) {
        t2.emplace_back(map[0][j],map[0][j]);
    }
    ans.push_back(t2);
    for(int i=1; i<height; i++) {
        vector<pair<int, int>> temp(width, {1, 1});
        for(int j=0; j<width; j++) {
            if(!map[i][j]) {
                temp[j] = {0,0}; continue;
            }
            if(j>0 && map[i-1][j-1]) temp[j].second = ans[i-1][j-1].second+1;
            if(j<width-1 && map[i-1][j+1]) temp[j].first = ans[i-1][j+1].first+1;
        }
        ans.push_back(temp);
    }

    vector<pair<int, int>> t3;
    for(int j=0; j<width; j++) {
        t3.emplace_back(map[height-1][j],map[height-1][j]);
    }
    ans2[height-1] = t3;
    for(int i=height-2; i>=0; i--) {
        vector<pair<int, int>> temp(width, {1, 1});
        for(int j=0; j<width; j++) {
            if(!map[i][j]) {
                temp[j] = {0,0}; continue;
            }
            if(j>0 && map[i+1][j-1]) temp[j].second = ans2[i+1][j-1].second + 1;
            if(j<width-1 && map[i+1][j+1]) temp[j].first = ans2[i+1][j+1].first + 1;

            maxi = max(maxi, min(min(ans[i][j].first, temp[j].first), min(temp[j].second, ans[i][j].second)));
        }
        ans2[i] = temp;
    }

    //for(int )

    /*
    for(auto a : ans) {
        for(auto [fst, snd] : a) cout << fst;
        cout << "\n";
    }
    cout << "\n";
    for(auto a : ans) {
        for(auto [fst, snd] : a) cout << snd;
        cout << "\n";
    }
    cout << "\n";
    for(auto a : ans2) {
        for(auto [fst, snd] : a) cout << fst;
        cout << "\n";
    }
    cout << "\n";
    for(auto a : ans2) {
        for(auto [fst, snd] : a) cout << snd;
        cout << "\n";
    }*/

    cout << maxi;
}