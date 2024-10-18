#include <bits/stdc++.h>
using namespace std;
vector<string> splitf(string s, string delimiter)
{
    vector<string> ret;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        ret.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    ret.push_back(s);
    return ret;
}

std::string gcd (std::string a, std::string b) { if(stoull(a) > stoull(b)){ swap(a,b); } 
while(stoull(a))
{ b = to_string(stoull(b) % stoull(a)); 
swap(a,b); } 
return b; }

int main()
{
    string temp = "165";
    cout << stoull(temp) << endl;
    cout << strcmp(typeid(vector<string>).name(), typeid(temp).name());
    string a = "210", b = "165";
    cout << gcd(a, b);
}