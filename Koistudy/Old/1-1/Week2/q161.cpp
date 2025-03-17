#include <iostream>
using namespace std;
int main()
{
    string a, b, c; cin >> a >> b >> c;
    cout << b[0] << '-' << b[1] << " NO." << stoi(b.substr(2)) << "\n" << c << "(" << ((a[7]-'0')&1?'M':'F') << ")\nBirthDay " << stoi(a.substr(2, 2)) << "/" << stoi(a.substr(4, 2));
}