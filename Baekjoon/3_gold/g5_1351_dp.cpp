#include <stdio.h>
#include <map>
#define lint long long int

//무한 수열

lint n, p, q;
std::map<lint, lint> m;

lint func(lint a);

int main()
{
    scanf("%lld %lld %lld", &n, &p, &q);
    printf("%lld", func(n));
}

lint func(lint a)
{
    if(a==0) return 1;
    auto res = m.find(a);
    if(res != m.end())
        return res->second;

    lint ans = func(a/p) + func(a/q);
    m.insert({a, ans});
    return ans;
}
