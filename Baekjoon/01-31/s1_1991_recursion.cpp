#include <iostream>
#include <vector>
using namespace std;

string preorder_traversal(vector<char> &left, vector<char> &right, char c) {
    if(c == '.') return "";
    return c + preorder_traversal(left, right, left[c-'A']) + preorder_traversal(left, right, right[c-'A']);
}

string inorder_traversal(vector<char> &left, vector<char> &right, char c) {
    if(c == '.') return "";
    return inorder_traversal(left, right, left[c-'A']) + c + inorder_traversal(left, right, right[c-'A']);
}

string postorder_traversal(vector<char> &left, vector<char> &right, char c) {
    if(c == '.') return "";
    return postorder_traversal(left, right, left[c-'A']) + postorder_traversal(left, right, right[c-'A']) + c;
}

int main()
{
    int n; cin >> n;
    vector<char> left(n);
    vector<char> right(n);
    for(int i=0; i<n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        left[a-'A'] = b;
        right[a-'A'] = c;
    }
    cout << preorder_traversal(left, right, 'A') << "\n";
    cout << inorder_traversal(left, right, 'A') << "\n";
    cout << postorder_traversal(left, right, 'A') << "\n";
}