#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long

ll fact[(int)1e8+1];

ll N,M;

const ll p = 1e9+7;

inline ll fastPow(ll a,ll m){
    ll base = a;
    a = 1;
    while(m){
        if(m&1){
            a *= base;
            a %= p;
        }
        base *= base;
        base %= p;
        m>>=1;
    }
    return a;
}

inline ll modC(ll x,ll y){
    return ((fact[x] * fastPow(fact[y],p-2)%p)%p) * ((fastPow(fact[x-y], p-2)%p))%p;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>N>>M;
    int pl = N;
    int pr = N+M-1;
    fact[0]=1;
    for(int i=1;i<=pr;++i){
        fact[i] = (fact[i-1] * i)%p;
    }
    cout<<modC(pr,pl);
    return 0;
}
