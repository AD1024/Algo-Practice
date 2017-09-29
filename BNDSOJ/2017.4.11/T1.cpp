#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll fact[3010];
ll a[3010];
int N;
const ll MOD = 1000000007;

inline void init(){
    scanf("%d", &N);
    for(int i=1;i<=N;++i) scanf("%lld", &a[i]);
    fact[0]=1;
    for(int i=1;i<=3010;++i){
        fact[i] = (fact[i-1]%MOD * i%MOD) % MOD;
    }
}

inline ll ctexpand(){
    int k;
    ll ans = 1;
    for(int i=1;i<=N;++i){
        k=0;
        for(int j=i+1;j<=N;++j){
            if(a[j] < a[i]) ++k;
        }
        ans += (fact[N-i]%MOD * k%MOD) % MOD;
        ans %= MOD;
    }
    return ans;
}

int main(){
    init();
    cout<<ctexpand();
    return 0;
}