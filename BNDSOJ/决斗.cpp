#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long ll;

inline ll read(){
    ll a = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        a = a*10+ch-'0';
        ch=getchar();
    }
    return a;
}


struct Node{
    ll sum;
    ll mx;
}tree[101000<<2];

ll offset;
int N,M;
int cnt;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1

inline void Maintain(int rt){
    tree[rt].sum = tree[lson(rt)].sum + tree[rson(rt)].sum;
    tree[rt].mx = max(tree[lson(rt)].mx, tree[rson(rt)].mx);
}

inline void build(){
    for(cnt=1;cnt<=N+1;cnt<<=1);
    for(int i=cnt+1;i<=cnt+N;++i){
        tree[i].sum = read();
        tree[i].mx = tree[i].sum;
    }
    for(int i=cnt-1;i;--i) Maintain(i);
}

inline ll qMax(int l,int r){
    ll ans = -0x3f3f3f3f3f;
    for(l=cnt+l-1,r=cnt+r+1;l^r^1;l>>=1,r>>=1){
        if(~l&1){
            ans = max(ans, tree[l^1].mx);
        }
        if(r&1){
            ans = max(ans, tree[r^1].mx);
        }
    }
    return ans + offset;
}

inline ll qSum(int l,int r){
    ll ans = 0;
    int pl = l,pr = r;
    for(l=cnt+l-1,r=cnt+r+1;l^r^1;l>>=1,r>>=1){
        if(~l&1) ans += tree[l^1].sum;
        if(r&1) ans += tree[r^1].sum;
    }
    return ans + (ll)(pr-pl+1) * offset;
}

int main(){
    N=read();M=read();
    build();
    int op;int Li,Ri;ll x;
    while(M--){
        scanf("%d", &op);
        if(op == 1){
            Li = read();Ri=read();
            printf("%lld\n", qMax(Li,Ri));
        }else if(op == 2){
            Li = read();Ri=read();
            printf("%lld\n", qSum(Li,Ri));
        }else{
            x=read();
            offset += x;
        }
    }
    return 0;
}