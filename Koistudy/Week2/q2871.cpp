#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s; cin >> s;
    vector<int> aa;
    for(int i=0; i<s.length(); i++) 
        if(s[i]=='.') aa.push_back(i);
    string a = (s.substr(2, 2)), b = (s.substr(aa[0]+1, aa[1]-aa[0]-1)), c = (s.substr(aa[1]+1));
    if(b.length()==1) b = '0' + b;
    if(c.length()==1) c = '0' + c;
    cout << a << b << c << "-XXXXXXX";
}