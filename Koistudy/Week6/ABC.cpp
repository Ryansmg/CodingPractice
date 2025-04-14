#include <bits/stdc++.h>
using namespace std;

int n; string s;

void preorder(int i) {
    if(i > n) return;
    cout << s[i-1] << " ";
    preorder(i * 2); preorder(i * 2 + 1);
}

void inorder(int i) {
    if(i > n) return;
    inorder(i * 2);
    cout << s[i-1] << " ";
    inorder(i * 2 + 1);
}

void postorder(int i) {
    if(i > n) return;
    postorder(i * 2);
    postorder(i * 2 + 1);
    cout << s[i-1] << " ";
}

int main() {
    cin >> n; cin >> s;
//    preorder(1);
//    inorder(1);
    postorder(1);
}
