#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> endic;
map<int, string> dedic;
string a;
int ecnt, dcnt, ck, enc[10000];
int main()
{
    int i;
    dcnt = 1;
    cin >> a;
    char c;
    for (i = 0; i < a.size(); i++)
    {
        string s = "";
        s = s + a[i];
        if (endic.find(s) != endic.end())
            continue;
        endic.insert({s, dcnt});
        dedic.insert({dcnt, s});
        dcnt++;
    }
    ecnt = 1;
    string s = "";
    for (i = 0; i < a.size(); i++)
    {
        if (endic.find(s + a[i]) != endic.end())
        {
            s = s + a[i];
        }
        else
        {
            enc[ecnt] = endic[s];
            ecnt++;
            endic.insert({s + a[i], dcnt});
            dedic.insert({dcnt, s + a[i]});
            dcnt++;
            s = a[i];
            s = a[i];
        }
    }
    enc[ecnt] = endic[s];
    ecnt++;
    dcnt--;
    cout << dcnt << endl;
    for (i = 1; i <= dcnt; i++)
        cout << i << " " << dedic[i] << endl;
    ecnt--;
    for (i = 1; i <= ecnt; i++)
        cout << enc[i] << " ";
    cout << endl;
    for (i = 1; i <= ecnt; i++)
        cout << dedic[enc[i]];
    return 0;
}