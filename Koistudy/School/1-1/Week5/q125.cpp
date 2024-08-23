#include <bits/stdc++.h>
#define USE_FAST_IO true
#define ll long long
#define ull unsigned ll
#define if(boolVal) if(boolVal){
#define else } else {
#define ifend }
#define while(boolVal) while(boolVal){
#define whileend }
#define decRange(varName, limit) vector<string> varName; int limitInt = int(limit); for(int iii=0; iii<limitInt; iii++) varName.push_back(to_string(iii));
#define declareRangeFunc vector<string> rangef(string limit) { decRange(var, limit) return var; }
#define declareInputFunc string inputf() { string in; cin >> in; return in; }
#define defSplitF vector<string> splitf(string s, string delimiter) { vector<string> ret; size_t pos = 0; string token; while ((pos = s.find(delimiter)) != string::npos) token = s.substr(0, pos); ret.push_back(token); s.erase(0, pos + delimiter.length()); end(while) ret.push_back(s); return ret; }
#define defMapIntF vector<int> mapIntf(vector<string> arr) { vector<int> ret; for(string s : arr) ret.push_back(stoi(s)); return ret; }
#define str(val) to_string(val)
#define dectostr string tostr(string s) { return s; } string tostr(int s) { return str(s); }
#define input() inputf()
#define declareFuncs declareRangeFunc declareInputFunc dectostr defSplitF
#define range(limit) rangef(tostr(limit))
#define st  using namespace std; declareFuncs int main()
#define st2 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define start st { string inputStr; if(USE_FAST_IO) st2 ifend
// #define end }
#define end(type) }
#define dec(name, value) string name = tostr(value);
#define def dec
#define set(name, value) name = tostr(value);
#define print(value) cout << value << "\n";
#define int(strValue) (stoi(strValue))
#define bool(strVal) (stoi(strVal)!=0)
#define float(val) (stof(val))
#define swap(a,b) swap(a,b);
#define AND &&
#define OR ||
#define forin(varName, arr) for(string varName : arr) {
#define forend }
#define max(a, b) max(int(a), int(b))
#define min(a, b) min(int(a), int(b))
#define tern(val1, condbool, val2) (condbool ? val1 : val2) //ternary operator, 삼항연산자
#define expdef(type, varname) type varname;
#define mapint(varname, strarr) varname = mapIntf(strarr);
#define split(str, div) (splitf(str, div))


start

def(a, input())
def(b, input())
if(int(a)>int(b))
    swap(a,b)
end(if)

def(ans, 0)

forin(i, range(int(b)-int(a)+1))
    def(v, int(i)+int(a))
    def(now, 1)
    while(int(v)!=1)
        set(now, int(now) + 1)
        if(int(v)&1)
            set(v, int(v)*3+1)
        else
            set(v, int(v)/2)
        end(if)
    end(while)
    set(ans, max(ans, now))
end(for)
print(ans)

end(program)

