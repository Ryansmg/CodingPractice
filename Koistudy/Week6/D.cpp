#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<string> tree(1);

void inorder(int i) {
    if(i >= ssize(tree)) return;
    if(!isdigit(tree[i][0])) cout << "(";
    inorder(i * 2);
    cout << tree[i];
    inorder(i * 2 + 1);
    if(!isdigit(tree[i][0])) cout << ")";
}

void postorder(int i) {
    if(i >= ssize(tree)) return;
    postorder(i * 2);
    postorder(i * 2 + 1);
    cout << tree[i] << " ";
}

i64 calc(int i) {
    if(isdigit(tree[i][0])) return stoll(tree[i]);
    if(tree[i][0] == '+') return calc(i * 2) + calc(i * 2 + 1);
    if(tree[i][0] == '-') return calc(i * 2) - calc(i * 2 + 1);
    if(tree[i][0] == '*') return calc(i * 2) * calc(i * 2 + 1);
    return calc(i * 2) / calc(i * 2 + 1);
}

int main() {
    string s;
    while(cin >> s) tree.push_back(s);
    inorder(1); cout << '\n';
    postorder(1); cout << '\n';
    cout << calc(1) << '\n';
}
