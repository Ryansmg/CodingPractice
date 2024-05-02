#include <bits/stdc++.h>
using namespace std;

vector<string> rangef(string limit)
{
    vector<string> varr;
    int limitInt = (stoi(limit));
    for (int iii = 0; iii < limitInt; iii++)
        varr.push_back(to_string(iii));
    return varr;
}
string inputf()
{
    string in;
    getline(cin, in);
    return in;
}
string tostr(string s) { return s; }
string tostr(int s) { return to_string(s); }
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
vector<int> mapIntf(vector<string> arr)
{
    vector<int> ret;
    for (string s : arr)
        ret.push_back(stoi(s));
    return ret;
}
string cinputf()
{
    string in;
    cin >> in;
    return in;
}

int main()
{
    string in = inputf();
    long long sq = sqrt(stoll(in));
    long long ans = 0;
    for (string i : rangef(tostr(sq)))
    {
        string j = tostr(stoll(i) + 1);
        if (stoll(in) % stoll(j) == 0)
        {
            ans = ans + stoll(j);
            ans = ans + (stoll(in) / stoll(j));
        }
    }

    if ((stoll(in) - sq * sq) == 0)
    {
        ans = ans - sqrt(stoll(in));
    }

    cout << ans << "\n";
}