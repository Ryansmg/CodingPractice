#include <bits/stdc++.h>

using namespace std;
vector<int> shika;
void PUSH(int x) {
    if(shika.empty()) {
        shika.push_back(x); return;
    }
    int i = shika.size()-1;
    shika.push_back(x);
    while(x > shika[i]) {
        shika[i+1] = shika[i];
        shika[i] = x;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // printf scanf 쓰면 안됨
    cin.tie(nullptr);

    int n;
    int x = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        //cout << x << "xxxxx\n";
        if(x == 0) {
            if(shika.empty()) {
                cout << "0 \n";
            }
            else {
                cout << shika.back() << "\n";
                shika.pop_back();
            }
        }
        else {
            PUSH(x);
        }

    }
}
