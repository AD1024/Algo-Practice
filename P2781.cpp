#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=10000010;
LL n,q;
LL T1[MAX],T2[MAX];
LL l,r,w;

inline LL lowbit(int x){
	return x&(-x);
}

inline void Update(LL x,LL d,LL *c){
    while(x<=n){
        c[x]+=d;
        x+=lowbit(x);
    }
}

inline LL Query(LL x,LL *c){
    LL sum=0;
    while(x>0){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}

int main(){

    cin>>n>>q;
    int cmd;
    for(int i=0;i<q;++i){
        cin>>cmd;
        if(cmd==1){
            scanf("%lld%lld%lld",&l,&r,&w);
            Update(l,w,T1);
            Update(r+1,-w,T1);
            Update(l,l*w,T2);
            Update(r+1,-(r+1)*w,T2);
        }else{
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",Query(r,T1)*(r+1)-Query(l-1,T1)*w-Query(r,T2)+Query(l-1,T2));
        }
    }
    return 0;
}