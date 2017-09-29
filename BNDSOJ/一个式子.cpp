#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

typedef long long ll;

inline ll f(ll k){
    for(int i=sqrt(k);i;--i){
        if(!(k%(i*i))) k/=(i*i);
    }
    return k;
}

int main(){
    ll n;
    while(scanf("%lld", &n)!=EOF){
        ll p=f(n);
        ll ans = p+n+sqrt(p*n)*2;
        printf("%lld\n",ans);
    }
    return 0;
}