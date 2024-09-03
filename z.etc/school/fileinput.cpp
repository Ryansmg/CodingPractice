#include <bits/stdc++.h>
using namespace std;

void generate() {
    FILE* out1 = fopen(R"(C:\Users\ryans\Desktop\Coding\z.etc\school\rand1.txt)", "w");
    int n; scanf("%d", &n);
    srand(time(nullptr));
    for(int i=0; i<n; i++) fprintf(out1, "%d\n", rand());
    fclose(out1);

    ofstream out2(R"(C:\Users\ryans\Desktop\Coding\z.etc\school\rand2.txt)");
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0, 2147483647);
    for(int i=0; i<n; i++) out2 << dis(gen) << '\n';
    out2.close();
}

void separate() {
    FILE* in1 = fopen(R"(C:\Users\ryans\Desktop\Coding\z.etc\school\rand1.txt)", "r");
    ifstream in2(R"(C:\Users\ryans\Desktop\Coding\z.etc\school\rand2.txt)");

    FILE* out1 = fopen(R"(C:\Users\ryans\Desktop\Coding\z.etc\school\min.txt)", "w");
    ofstream out2(R"(C:\Users\ryans\Desktop\Coding\z.etc\school\max.txt)");
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        fscanf(in1, "%d", &a);
        in2 >> b;
        if(a > b) swap(a, b);
        fprintf(out1, "%d\n", a);
        out2 << b << '\n';
    }
    fclose(in1); fclose(out1);
    in2.close(); out2.close();
}

#define lint long long
#define v vector
struct prs{
    prs(){B={2,3,5,7,11,13,17,19,23,29,31,37,41};E=mt19937(random_device()());}bool isPrime(lint n){if(n<=1)return 0;for(const lint &a:B)if(!_(n,a))return 0;return 1;}
    lint factorize(const lint&n){if(n%2==0)return 2;if(isPrime(n))return n;lint x=D(E)%(n-2)+2,y=x,c=D(E)%10+1,g=1;while(g==1){x=(x*x%n+c)%n;y=(y*y%n+c)%n;y=(y*y%n
    +c)%n;g=G(x-y>0?x-y:y-x,n);if(g==n)return factorize(n);}if(isPrime(g))return g;else return factorize(g);}lint p(lint a,lint b,lint m){a%=m;lint z=1;while(
                b){if(b&1)z=z*a%m;b>>=1;a=a*a%m;}return z;}lint G(lint a,lint b) {if(a<b)swap(a,b);while(b){lint r=a%b;a=b;b=r;}return a;}v<lint>B;mt19937 E;uniform_int_distribution
            <lint>D;bool _(lint n,lint a){if(a%n==0)return 1;lint d=n-1;while(1){lint t=p(a,d,n);if(t==n-1)return 1;if(d%2)return(t==1||t==n-1);d/=2;}}
} prs;

void getPrimes() {
    int n; cin >> n;
    FILE* out = fopen(R"(C:\Users\ryans\Desktop\Coding\z.etc\school\prime.txt)", "w");
    for(int i=2; i<=n; i++) {
        if(prs.isPrime(i)) fprintf(out, "%d\n", i);
    }
    fclose(out);
}

int main() {
    generate();
    separate();
    getPrimes();
}
