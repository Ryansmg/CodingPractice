#include <iostream>
#include <vector>
using namespace std;

// 5670. 휴대폰 자판
// #trie
// https://rebro.kr/86

struct trie {
    trie* nxt[26]; //a~z
    bool end = false;
    trie() {
        for(int i=0; i<26; i++) nxt[i] = NULL;
    }
    ~trie() {
        for (int i = 0; i < 26; i++) if (nxt[i] != NULL) delete nxt[i];
    }
    void insert(const char* str) {
        if(!*str) end = true;
        else {
            int idx = *str - 'a';
            if(!nxt[idx]) nxt[idx] = new trie;
            nxt[idx]->insert(str+1);
        }
    }
    int getChildCnt() {
        int ans = 0;
        for(int i=0; i<26; i++) 
            if(nxt[i] != NULL) ans++;
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    cout << fixed;
    cout.precision(2);
    int n;
    while(cin >> n) {
        vector<string> strs;
        trie tri;
        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            tri.insert(s.c_str());
            strs.push_back(s);
        }
        int sum = 0;
        for(string str : strs) {
            int len = str.length();
            int ans = len;
            trie* src = &tri;
            for(int i=0; i<len; i++) {
                if(src->getChildCnt()==1 && !src->end) ans--;
                src = src->nxt[str[i]-'a'];
            }
            if(tri.getChildCnt()==1 && !tri.end) ans++;
            sum += ans;
        }
        cout << sum / (double) n << "\n";
    }
}
