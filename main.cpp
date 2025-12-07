#include <bits/stdc++.h>
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target ("avx,avx2,fma")
using namespace std;

#define big __int128_t
#define ll long long
#define int ll
#define endl '\n'
#define Endl '\n'
#define fio ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define pii pair<int,int>
#define arr vector<int>
#define parr vector<pii>
#define check cout<<'e'<<endl;
#define append push_back

struct node
{
    node* l;
    node* r;
    node* p;
    int key,cnt,mn,sum,mx,mxi,idx;
    bool ff,rev;
    node(int k,int i)
    {
        l=nullptr;
        r=nullptr;
        p=nullptr;
        cnt=1;
        key=k;
        mn=k;
        mx=k;
        mxi=i;
        idx=i;
        sum=k;
        ff=false;
        rev=false;
    }
};
node* tree=nullptr;
node* a[301010];

void push(node* x)
{
    if (!x->rev) return;
    swap(x->l,x->r);
    if (x->l) x->l->rev^=1;
    if (x->r) x->r->rev^=1;
    x->rev=false;
}
void upd(node* x)
{
    x->mx=x->key;
    x->mxi=x->idx;
    if (x->l) 
    {
        if (x->l->mx>x->mx) 
        {
            x->mx=x->l->mx;
            x->mxi=x->l->mxi;
        }
    }
    if (x->r) 
    {
        if (x->r->mx>x->mx) 
        {
            x->mx=x->r->mx;
            x->mxi=x->r->mxi;
        }
    }
}

bool istree(node* x)
{
    return !x->p || (x!=x->p->l && x!=x->p->r);
}


void rotate(node* x)
{
    node* p=x->p;
    node* b=nullptr;
    if (!p) return;
    push(p);
    push(x);

    if (x==p->l)
    {
        if (x->r) x->r->p=x->p;
        x->p->l=x->r;
        x->r=x->p;
    }
    else
    {
        if (x->l) x->l->p=x->p;
        x->p->r=x->l;
        x->l=x->p;
    }
    if (!istree(x->p))
    {
        if (x->p==x->p->p->l)
        {
            x->p->p->l=x;
        }
        else
        {
            x->p->p->r=x;
        }
    }
    node* temp=x->p;
    x->p=temp->p;
    temp->p=x;
    upd(p);
    upd(x);
}

void splay(node* x)
{
    push(x);
    while (!istree(x))
    {
        if (!istree(x->p)) push(x->p->p);
        push(x->p);
        push(x);
        node* p=x->p;
        node* pp=p->p;
        if (istree(p))
        {
            rotate(x);
            break;
        }
        else
        {
            if ((x==p->l && p==pp->l)||(x==p->r && p==pp->r))
            {
                rotate(p);
            }
            else
            {
                rotate(x);
            }
        }
        rotate(x);
    }
    push(x);
}

void access(node* x)
{
    splay(x);
    x->r=nullptr; upd(x);
    while (x->p)
    {
        splay(x->p);
        x->p->r=x; upd(x->p);
        splay(x);
    }
}

node* root(node* x)
{
    access(x);
    while (x->l) 
    {
        x=x->l;
        push(x);
    }
    splay(x);
    return x;
}

void toroot(node* x)
{
    access(x);
    splay(x);
    x->rev^=1;
}


void cut(node* x)
{
    access(x);
    if (!x->l) return;
    x->l->p=nullptr;
    x->l=nullptr;
    upd(x);
}

node* lca(node* p,node* q)
{
    access(p);
    access(q);
    splay(p);
    if (p->p) return p->p;
    else return p;
}

void updd(node* x,int c)
{
    splay(x);
    x->key=c;
    upd(x);
}

void link(node* p,node* x)
{
    toroot(x);
    access(x);
    access(p);
    x->l=p;
    p->p=x;
    upd(x);
}

int cnt,n,t;
parr e;
void linkk(node* p,node* q,int c)
{
    node* x=a[n+cnt]=new node(c,n+cnt);
    e.append({p->idx,q->idx});
    t+=c;
    cnt++;
    link(p,x);
    link(x,q);
}

void cutt(node* p, node* x, node* y)
{
    toroot(x); 
    access(y); 
    splay(p); 
    t-=p->key;
    if (p->l) p->l->p=nullptr;
    if (p->r) p->r->p=nullptr;
    p->l=nullptr;
    p->r=nullptr;
    upd(p);
}

void hquery(node* u,node* v,int c)
{
    toroot(u);
    access(v);
    splay(v);
    int mx=v->mx;
    int mxi=v->mxi;
    if (mx>c)
    {
        cutt(a[mxi],a[e[mxi-n].fi],a[e[mxi-n].se]);
        linkk(u,v,c);
    }
}

void solve()
{
    int m;
    cin>>n>>m;
    t=0;
    cnt=0;
    e.clear();
    for (int i=0;i<301010;i++) a[i]=nullptr;
    a[0]=new node(-1,0);
    for (int i=1;i<n;i++)
    {
        a[i]=new node(-1,i);
        int p,q;cin>>p>>q;
        linkk(a[i],a[p],q);
    }
    int ans=0;
    for (int i=0;i<m;i++)
    {
        int s,f,c;
        cin>>s>>f>>c;
        hquery(a[s],a[f],c);
        ans^=t;
    }
    cout<<ans<<endl;
}

signed main()
{
    fio
    int T;
    cin>>T;
    while (T--) solve();
}