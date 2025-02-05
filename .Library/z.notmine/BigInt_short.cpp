/* Updated : 2025-02-06 */
// ~10000B

#include <bits/stdc++.h>

const int BASE_DIGITS=9;const int BASE=1000000000;
class BigInt {//@formatter:off
  int sign;std::vector<int>M;
public:
  BigInt():sign(1){}//Default constructor.
  BigInt(long long v):sign(1){*this=v;}//Constructor from long long.//NOLINT(*-explicit-constructor)
  BigInt&operator=(long long v){sign=1;M.clear();if(v<0)sign=-1,v=-v;for(;v>0;v=v/BASE)M.push_back(v%BASE);return*this;}
  BigInt(const std::string&s):sign(1){read(s);}//Initialize from string.//NOLINT(*-explicit-constructor)
  void read(const std::string&s){sign=1;M.clear();int pos=0;while(pos<(int)s.size()&&(s[pos]=='-'||s[pos]=='+')){if(s[pos]=='-'){sign=-sign;}++pos;}
    for(int i=s.size()-1;i>=pos;i-=BASE_DIGITS){int x=0;for(int j=std::max(pos,i-BASE_DIGITS+1);j<=i;j++){x=x*10+s[j]-'0';}M.push_back(x);}trim();}
  friend std::istream&operator>>(std::istream&t,BigInt&v){std::string s;t>>s;v.read(s);return t;}
  friend std::ostream&operator<<(std::ostream&t,const BigInt&v){if(v.sign==-1&&!v.isZero()){t<<'-';}t<<(v.M.empty()?0:v.M.back());
    for(int i=(int)v.M.size()-2;i>=0;--i){t<<std::setw(BASE_DIGITS)<<std::setfill('0')<<v.M[i];}return t;}
  bool operator<(const BigInt&v)const{if(sign!=v.sign){return sign<v.sign;}if(M.size()!=v.M.size()){return M.size()*sign<v.M.size()*v.sign;}
    for(int i=((int)M.size())-1;i>=0;i--){if(M[i]!=v.M[i]){return M[i]*sign<v.M[i]*sign;}}return false;}
  bool operator>(const BigInt&v)const{return v<*this;}bool operator<=(const BigInt&v)const{return!(v<*this);}
  bool operator>=(const BigInt&v)const{return!(*this<v);}bool operator==(const BigInt&v)const{return!(*this<v)&&!(v<*this);}
  bool operator!=(const BigInt&v)const{return*this<v||v<*this;}
  BigInt operator-()const{BigInt res=*this;if(isZero()){return res;}res.sign=-sign;return res;}
private:
  friend int cmpAbs_(const BigInt&x,const BigInt&y){if(x.M.size()!=y.M.size()){return x.M.size()<y.M.size()?-1:1;}//Returns:0 if|x|==|y|,-1 if|x|<|y|,1 if|x|>|y|
    for(int i=((int)x.M.size())-1;i>=0;--i){if(x.M[i]!=y.M[i]){return x.M[i]<y.M[i]?-1:1;}}return 0;}
  void i_add_(const BigInt&v){if(M.size()<v.M.size()){M.resize(v.M.size(),0);}//Note:sign ignored.
    for(int i=0,c=0;i<(int)std::max(M.size(),v.M.size())||c;++i){if(i==(int)M.size()){M.push_back(0);}M[i]+=c+(i<(int)v.M.size()?v.M[i]:0);c=M[i]>=BASE;if(c)M[i]-=BASE;}}
  void i_sub_(const BigInt&v){for(int i=0,c=0;i<(int)v.M.size()||c;++i){M[i]-=c+(i<(int)v.M.size()?v.M[i]:0);c=M[i]<0;if(c)M[i]+=BASE;}this->trim();}//Note:sign ignored.
public:
  BigInt operator+=(const BigInt&v){if(sign==v.sign){i_add_(v);}else{if(cmpAbs_(*this,v)>=0){
    i_sub_(v);}else{BigInt vv=v;std::swap(*this,vv);i_sub_(vv);}}return*this;}
  BigInt operator-=(const BigInt&v){if(sign==v.sign){if(cmpAbs_(*this,v)>=0){i_sub_(v);}else{BigInt vv=v;std::swap(*this,vv);i_sub_(vv);this->sign=-this->sign;}}else{i_add_(v);}return*this;}
  template<typename L,typename R>typename std::enable_if<std::is_convertible<L,BigInt>::value&&std::is_convertible<R,BigInt>::value&&std::is_lvalue_reference<R&&>::value,BigInt>::type friend operator+(L&&l,R&&r){BigInt u(std::forward<L>(l));u+=r;return u;}
  template<typename L,typename R>typename std::enable_if<std::is_convertible<L,BigInt>::value&&std::is_convertible<R,BigInt>::value&&std::is_rvalue_reference<R&&>::value,BigInt>::type friend operator+(L&&l,R&&r){BigInt u(std::forward<R>(r));u+=l;return u;}
  template<typename L,typename R>typename std::enable_if<std::is_convertible<L,BigInt>::value&&std::is_convertible<R,BigInt>::value,BigInt>::type friend operator-(L&&l,R&&r){BigInt u(std::forward<L>(l));u-=r;return u;}
  friend std::pair<BigInt,BigInt>divMod(const BigInt&A,const BigInt&B){assert(B>0);//divMod not well-defined for b<0.
    long long m=BASE/(B.M.back()+1);BigInt a=A.abs()*m,b=B.abs()*m,q=0,r=0;q.M.resize(a.M.size());
    for(int i=a.M.size()-1;i>=0;i--){r*=BASE;r+=a.M[i];
      long long s1=r.M.size()<=b.M.size()?0:r.M[b.M.size()],s2=r.M.size()<=b.M.size()-1?0:r.M[b.M.size()-1],d=((long long)BASE*s1+s2)/b.M.back();
      r-=b*d;while(r<0){r+=b,--d;}q.M[i]=d;}q.sign=A.sign*B.sign;r.sign=A.sign;q.trim();r.trim();
    auto R=std::make_pair(q,r/m);if(R.second<0){R.second+=B;}return R;}
  BigInt operator/(const BigInt&v)const{return divMod(*this,v).first;}BigInt operator%(const BigInt&v)const{return divMod(*this,v).second;}
  void operator/=(int v){assert(v>0);//operator/ not well-defined for v<=0.
    if(llabs(v)>=BASE){*this/=BigInt(v);return;}
    for(int i=(int)M.size()-1,rem=0;i>=0;--i){long long c=M[i]+rem*(long long)BASE;M[i]=(int)(c/v);rem=(int)(c%v);}trim();}
  BigInt operator/(int v)const{assert(v>0);//operator/ not well-defined for v<=0.
    if(llabs(v)>=BASE){return*this/BigInt(v);}BigInt r=*this;r/=v;return r;}
  void operator/=(const BigInt&v){*this=*this/v;}
  long long operator%(long long v)const{assert(v>0);//operator/ not well-defined for v<=0.
    assert(v<BASE);int m=0;for(int i=M.size()-1;i>=0;--i){m=(M[i]+m*(long long)BASE)%v;}return m*sign;}
  void operator*=(int v){if(llabs(v)>=BASE){*this*=BigInt(v);return;}if(v<0){sign=-sign,v=-v;}
    for(int i=0,c=0;i<(int)M.size()||c;++i){if(i==(int)M.size()){M.push_back(0);}
      long long u=M[i]*(long long)v+c;c=(int)(u/BASE);M[i]=(int)(u%BASE);}trim();}
  BigInt operator*(int v)const{if(llabs(v)>=BASE){return*this*BigInt(v);}BigInt r=*this;r*=v;return r;}
private:
  static std::vector<int>cb_(const std::vector<int>&a,int od,int nd){//Convert BASE 10^old-->10^new.
    std::vector<long long>p(std::max(od,nd)+1);p[0]=1;for(int i=1;i<(int)p.size();i++){p[i]=p[i-1]*10;}std::vector<int>r;long long c=0;int cd=0;
    for(int i:a){c+=i*p[cd];cd+=od;while(cd>=nd){r.push_back((long long)(c%p[nd]));c/=p[nd];cd-=nd;}}
    r.push_back((int)c);while(!r.empty()&&!r.back()){r.pop_back();}return r;}
  using base=std::complex<double>;
  static void fft(std::vector<base>&a,bool inv){int n=a.size();std::vector<base>r(n/2);
    for(int i=1,j=0;i<n;i++){int bit=(n>>1);while(j>=bit){j-=bit;bit>>=1;}j+=bit;if(i<j)swap(a[i],a[j]);}
    double g=2*acos(double(-1))/n*(inv?-1:1);
    for(int i=0;i<n/2;i++){r[i]=base(cos(g*i),sin(g*i));}
    for(int i=2;i<=n;i<<=1){int t=n/i;for(int j=0;j<n;j+=i)for(int k=0;k<i/2;k++){base u=a[j+k],v=a[j+k+i/2]*r[t*k];a[j+k]=u+v;a[j+k+i/2]=u-v;}}
    if(inv)for(int i=0;i<n;i++)a[i]/=n;}
  static void mfft_(const std::vector<int>&a,const std::vector<int>&b,std::vector<int>&res){
    std::vector<base>fa(a.begin(),a.end()),fb(b.begin(),b.end());
    int n=1;while(n<(int)std::max(a.size(),b.size())){n<<=1;}n<<=1;fa.resize(n);fb.resize(n);
    fft(fa,false);fft(fb,false);for(int i=0;i<n;++i){fa[i]*=fb[i];}fft(fa,true);
    res.resize(n);long long c=0;for(int i=0;i<n;++i){long long t=llround(fa[i].real())+c;c=t/1000;res[i]=t%1000;}}
  BigInt ms_(const BigInt&v)const{BigInt r;r.sign=sign*v.sign;r.M.resize(M.size()+v.M.size());
    for(int i=0;i<(int)M.size();++i)if(M[i])for(int j=0,c=0;j<(int)v.M.size()||c;++j){long long t=r.M[i+j]+(long long)M[i]*(j<(int)v.M.size()?v.M[j]:0)+c;c=(int)(t/BASE);r.M[i+j]=(int)(t%BASE);}
    r.trim();return r;} typedef std::vector<long long>vll;
  static vll km_(const vll&a,const vll&b){int n=a.size();vll e(n+n);if(n<=32){for(int i=0;i<n;i++){for(int j=0;j<n;j++)e[i+j]+=a[i]*b[j];}return e;}
    int k=n>>1;vll A(a.begin(),a.begin()+k),B(a.begin()+k,a.end()),C(b.begin(),b.begin()+k),D(b.begin()+k,b.end()),E=km_(A,C),F=km_(B,D);
    for(int i=0;i<k;i++){B[i]+=A[i];}for(int i=0;i<k;i++){D[i]+=C[i];}vll r=km_(B,D);for(int i=0;i<(int)E.size();i++){r[i]-=E[i];}for(int i=0;i<(int)F.size();i++){r[i]-=F[i];}
    for(int i=0;i<(int)r.size();i++){e[i+k]+=r[i];}for(int i=0;i<(int)E.size();i++){e[i]+=E[i];}for(int i=0;i<(int)F.size();i++){e[i+n]+=F[i];}return e;}
  BigInt mk_(const BigInt&v)const{
    std::vector<int>a6=cb_(this->M,BASE_DIGITS,6),b6=cb_(v.M,BASE_DIGITS,6);
    vll a(a6.begin(),a6.end()),b(b6.begin(),b6.end());while(a.size()<b.size()){a.push_back(0);}while(b.size()<a.size()){b.push_back(0);}
    while(a.size()&(a.size()-1)){a.push_back(0),b.push_back(0);}vll c=km_(a,b);BigInt res;res.sign=sign*v.sign;long long r=0;
    for(long long i:c){long long u=i+r;res.M.push_back((int)(u%1000000));r=u/1000000;}res.M=cb_(res.M,6,BASE_DIGITS);res.trim();return res;}
  BigInt mul_fft(const BigInt&v)const{BigInt res;res.sign=sign*v.sign;mfft_(cb_(M,BASE_DIGITS,3),cb_(v.M,BASE_DIGITS,3),res.M);
    res.M=cb_(res.M,3,BASE_DIGITS);res.trim();return res;}
public:
  void operator*=(const BigInt&v){*this=*this*v;}
  BigInt operator*(const BigInt&v)const{if(M.size()<32||v.M.size()<32){return ms_(v);}if(M.size()>100111||v.M.size()>100111){return mul_fft(v);}return mk_(v);}
  BigInt abs()const{BigInt r=*this;r.sign*=r.sign;return r;}void trim(){ while(!M.empty()&&!M.back()){M.pop_back();}if(M.empty())sign=1;}
  bool isZero()const{return M.empty()||(M.size()==1&&!M[0]);}friend BigInt gcd(const BigInt&a,const BigInt&b){return b.isZero()?a:gcd(b,a%b);}
  friend BigInt lcm(const BigInt&a,const BigInt&b){return a/gcd(a,b)*b;}
  friend BigInt sqrt(const BigInt&a1){BigInt a=a1;while(a.M.empty()||a.M.size()%2==1){a.M.push_back(0);}int n=a.M.size(),f=(int)sqrt((double)a.M[n-1]*BASE+a.M[n-2]),m=BASE/(f+1);
    a*=m;a*=m;while(a.M.empty()||a.M.size()%2==1){a.M.push_back(0);}BigInt r=(long long)a.M[n-1]*BASE+a.M[n-2];f=(int)sqrt((double)a.M[n-1]*BASE+a.M[n-2]);int q=f;BigInt res;
    for(int j=n/2-1;j>=0;j--){for(;;--q){BigInt r1=(r-(res*2*BigInt(BASE)+q)*q)*BigInt(BASE)*BigInt(BASE)+(j>0?(long long)a.M[2*j-1]*BASE+a.M[2*j-2]:0);
      if(r1>=0){r=r1;break;}}res*=BASE;res+=q;if(j>0){int d1=res.M.size()+2<r.M.size()?r.M[res.M.size()+2]:0,d2=res.M.size()+1<r.M.size()?r.M[res.M.size()+1]:0,
        d3=res.M.size()<r.M.size()?r.M[res.M.size()]:0;q=((long long)d1*BASE*BASE+(long long)d2*BASE+d3)/(f*2);}}res.trim();return res/m;}
};//@formatter:on
