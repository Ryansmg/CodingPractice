#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct city {
    int money, people;
    city(){}
    city(int a, int b) {
        money=a; people=b;
    }
};

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c, n; cin>>c>>n;
    vector<city> cities;
    int ta, tb;
    for(int i=0; i<n; i++) {
        cin>>ta>>tb;
        cities.emplace_back(ta, tb);
    }
    vector<int> maxpeo(1, 0); //[사용한 비용] => 최대 사람 수
    int curwgh = 0; //구하고 있는 비용
    while(1) {
        curwgh++;
        maxpeo.push_back(0);
        for(city c : cities) {
            if (curwgh - c.money < 0) continue;
            maxpeo[curwgh] = max(maxpeo[curwgh], maxpeo[curwgh-c.money] + c.people);
        }
        if(maxpeo[curwgh] >= c) break;
    }
    cout << curwgh;
}

