#include <bits/stdc++.h>
using namespace std;
#define USE_FAST_IO false
#define vll long long //var_ll
#define vull unsigned long long //var_ull, ull()과 구분
#define ll(str) stoll(str)
#define ull(str) stoull(str)
#define if(boolVal) if(boolVal){
#define else } else {
#define ifend }
#define while(boolVal) while(boolVal){
#define whileend }
#define decRange(varName, limit) vector<string> varName; int limitInt = int(limit); for(int iii=0; iii<limitInt; iii++) varName.push_back(to_string(iii));
#define declareRangeFunc vector<string> rangef(string limit) { decRange(varr, limit) return varr; }
#define declareInputFunc string inputf() { string in; getline(cin, in); return in; }
#define defSplitF vector<string> splitf(string s, string delimiter) { vector<string> ret; size_t pos = 0; string token; while ((pos = s.find(delimiter)) != string::npos) token = s.substr(0, pos); ret.push_back(token); s.erase(0, pos + delimiter.length()); end ret.push_back(s); return ret; }
#define defMapIntF vector<int> mapIntf(vector<string> arr) { vector<int> ret; for(string s : arr) ret.push_back(stoi(s)); return ret; }
#define str(val) to_string(val)
#define dectostr string tostr(string s) { return s; } string tostr(int s) { return str(s); }
#define input() inputf()
#define declareFuncs declareRangeFunc declareInputFunc dectostr defSplitF defMapIntF
#define range(limit) rangef(tostr(limit)) //[0, 1, ... , (limit-1)] (vector<string> 타입)을 반환
#define st declareFuncs int main()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //빠른 입출력 활성화
#define setiostart(useFastIo) st { string inputStr; if(useFastIo) fastio ifend
#define start setiostart(USE_FAST_IO)
#define end }
#define endif end //코드 가독성을 위함
#define endfor end
#define endwhile end
#define endprogram end
//#define end(type) }
#define dec(name, value) string name = value; //변수 선언, value는 str 타입이어야 함.
#define deca(name, value) dec(name, tostr(value)) //value의 타입 상관없이 변수 선언 (declare_auto)
#define def dec //define
#define defa deca //define_auto
#define set(name, value) name = value; //value의 타입이 str이어야 함.
#define seta(name, value) set(name, tostr(value)) //set_auto (value의 타입은 상관없음)
#define print(value) cout << value << "\n";
#define int(strValue) (stoi(strValue))
#define bool(strVal) (stoi(strVal)!=0)
#define float(val) (stof(val))
#define swap(a,b) swap(a,b);
#define AND &&
#define OR ||
#define expforin(type, varname, arr) for(type varname : arr) {
#define forin(varName, arr) expforin(string, varName, arr) //python3의 for varName in arr: 을 옮김.
#define forend }
#define max(a, b) max(int(a), int(b))
#define min(a, b) min(int(a), int(b))
#define tern(val1, condbool, val2) (condbool ? val1 : val2) //ternary operator, 삼항연산자
#define expdef(type, varname, value) type varname = value; //변수를 특정 타입으로 선언
#define mapint(varname, strarr) varname = mapIntf(strarr); //vector<string>을 vector<int>로 변환. (varname은 vector<int> 타입이어야 하므로 expdef()로 선언)
#define split(str, div) (splitf(str, div)) //str을 div로 split한 vector<string>을 반환.
#define expfunc(returntype, name, params) returntype name params { //함수 선언, start 전에 사용해야 하며, params는 소괄호로 묶어야 한다.
#define func(name, params) expfunc(std::string, name, params) //returntype이 string인 함수 선언, params는 소괄호로 묶어야 함.
#define endfunc(returnvalue) return returnvalue; } //함수 선언 종료, returnValue를 제공해야 함.
#define var std::string //funcdef에서 타입 이름에 사용
#define goto(name) goto name;
#define break break;
#define continue continue;
#define baseVal {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}

expfunc(vull, pow, (vull a, vull b, vull mod))
    expdef(vull, ans, 1)
    while(b)
        if(b&1)
            set(ans, ans * a % mod)
        endif
        set(b, b>>1)
        set(a, a * a % mod)
    endwhile
endfunc(ans)

expfunc(bool, _isPrime, (vull n, vull a))
    expdef(vull, temp, 1)
    expdef(vull, d, n-1)
    if(a%n==0)
        goto(_ipend)
    endif
    while(!d&1)
        if(pow(a, d, n) == n-1)
            goto(_ipend)
        endif
        set(d, d>>2)
    endwhile
    set(temp, pow(a, d, n))
    _ipend:
endfunc(temp == 1 || temp == n-1)

expfunc(bool, isPrime, (vull n))
    expdef(bool, result, true)
    expdef(vull, base[], baseVal)
    if(!n)
        set(result, false)
        goto(ipend)
    endif
    expforin(vull, a, base)
        if(!_isPrime(n, a))
            set(result, false)
            break
        endif
    endfor
    ipend:
endfunc(result)

func(gcd, (var a, var b))

    if(int(a) > int(b))
        swap(a,b)
    endif

    while(bool(a))
        set(b, int(b) % int(a))
        swap(a,b)    
    endwhile

endfunc(b)

start

forin(i, range(input()))
    def(in, input())
    print(tern("True", isPrime(ull(in)), "False"))
endfor

end
