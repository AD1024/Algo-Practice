#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define lowbit(x) (x & -x)

#define MAXN 3010
typedef long long ll;
ll tree[MAXN<<4];
ll fact[MAXN];
const ll MOD = 1000000007;
int M;int N;

inline ll getW(int x){
    ll ans = 0;
    while(x) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

inline void update(int p) {
    while(p <= N) {
        tree[p] += 1;
        p += lowbit(p);
    }
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
    ll ans=1;
    for(int i=1;i<=N;++i) scanf("%d", &a[i]);
    for(int i=N;i>=1;--i){
        ans += (fact[N-i]%MOD * getW(a[i]-1) % MOD) % MOD;
        ans %= MOD;
        update(a[i]);
    }
    printf("%lld", ans);
    return 0;
}