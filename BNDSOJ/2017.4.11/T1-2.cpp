#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1

#define MAXN 3010
typedef long long ll;
ll tree[MAXN<<4];
ll fact[MAXN];
const ll MOD = 1000000007;
int M;int N;

inline void Maintain(int i){
    tree[i] = tree[i<<1] + tree[i<<1|1];
}

inline void build(){
    for(M=1;M<N;M<<=1);
    for(int i=M+1;i<=M+N;++i) tree[i]=0;
}

inline void update(int pos){
    for(tree[pos+=M]+=1,pos>>=1;pos;pos>>=1){
        Maintain(pos);
    }
}

inline ll getW(int l,int r){
    int p=l,q=r;
    ll ans = 0;
    for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
        if(~l&1) ans += tree[l^1];
        if(r&1) ans += tree[r^1];
    }
    return ans;
}

inline void init(){
    scanf("%d", &N);
    fact[0] = 1;
    for(int i=1;i<=3005;++i){
        fact[i] = (fact[i-1]%MOD * i%MOD)%MOD;
    }
}
int a[3010];
int main(){
    init();
    build();
    ll ans=1;
    for(int i=1;i<=N;++i) scanf("%d", &a[i]);
    for(int i=N;i>=1;--i){
        // cout<<fact[N-i]<<" "<<getW(1, 1, a[i]-1)<<endl;
        ans += (fact[N-i]%MOD * getW(1, a[i]-1)%MOD) % MOD;
        ans %= MOD;
        update(a[i]);
    }
    printf("%lld", ans);
    return 0;
}