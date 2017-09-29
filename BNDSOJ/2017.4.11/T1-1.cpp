#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long ll;

struct Node{
    int lson,rson;
    int w;
};

Node tree[3010<<2];
ll ans = 1;
ll fact[3010];
int N;

const ll MOD = 1000000007;

#define rson(x) x<<1|1
#define lson(x) x<<1
#define lc(x) tree[x].lson
#define rc(x) tree[x].rson
#define tot(x) tree[x].w
#define Mid(x,y) (x+y) >> 1

inline void init(){
    scanf("%d", &N);
    fact[0] = 1;
    for(int i=1;i<=3005;++i){
        fact[i] = (fact[i-1]%MOD * i%MOD)%MOD;
    }
}

inline void Maintain(int rt){
    tot(rt) = tot(lson(rt)) + tot(rson(rt));
}

void build(int rt, int l,int r){
    tree[rt].lson = l;
    tree[rt].rson = r;
    if(l == r) return;
    else{
        int mid = Mid(l,r);
        build(lson(rt), l, mid);
        build(rson(rt), mid+1, r);
    }
}

void update(int rt,int pos){
    if(tree[rt].lson == pos && tree[rt].rson == tree[rt].lson){
        tot(rt) += 1;
    }else{
        int mid = Mid(lc(rt), rc(rt));
        if(pos <= mid){
            update(lson(rt), pos);
        }else{
            update(rson(rt), pos);
        }
        Maintain(rt);
    }
}

int getW(int rt,int l,int r){
    if(lc(rt) > r || rc(rt) < l) return 0;
    if(lc(rt) == l && rc(rt) == r){
        return tot(rt);
    }else{
        int mid = Mid(lc(rt), rc(rt));
        if(r <= mid){
            return getW(lson(rt), l, r);
        }else if(l > mid){
            return getW(rson(rt), l, r);
        }else{
            return getW(lson(rt), l, mid) + getW(rson(rt), mid+1, r);
        }
    }
}
int a[3010];
int main(){
    init();
    build(1, 1, N);
    for(int i=1;i<=N;++i){
        scanf("%d", &a[i]);
    }
    for(int i=N;i>=1;--i){
        // cout<<fact[N-i]<<" "<<getW(1, 1, a[i]-1)<<endl;
        ans += (fact[N-i]%MOD * getW(1, 1, a[i]-1)%MOD) % MOD;
        ans %= MOD;
        update(1, a[i]);
    }
    cout<<ans<<endl;
    return 0;
}

