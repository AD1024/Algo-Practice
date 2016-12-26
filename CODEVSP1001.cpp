#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 10010
int fa[MAXN];
int N,M;
struct Edge{
    int u,v,w;
}a[MAXN];
inline void initFa(){
    for(int i=1;i<=N;++i){
        fa[i]=i;
    }
}

int find(int x){
    while(x!=fa[x]){
        x=fa[x];
    }
    return x;
}

void Union(int x,int y){
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
        fa[xx]=yy;
}

bool cmp(Edge a,Edge b){
    return a.w<b.w;
}


inline int GCD(int a,int b){
    while(a^=b^=a^=b%=a);
    return b;
}

int from,to;

int main(){
    cin>>N>>M;
    for(int i=1;i<=M;++i){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    initFa();
    cin>>from>>to;
    for(int i=1;i<=M;++i){
        Union(a[i].u,a[i].v);
    }
    if(find(from)!=find(to)){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
	sort(a+1,a+M+1,cmp);
    double maxn=-100000;
    double minm=100000;
    double ans=1000000;
    int hi,lo;
    for(int i=1;i<=M;++i){
        initFa();
        maxn=a[i].w;
        for(int j=i;j>=1;j--){
            minm=a[j].w;
            Union(a[j].u,a[j].v);
            if(find(from)==find(to)){
                if(maxn/minm<ans){
                    hi=maxn;
                    lo=minm;
                    ans=maxn/minm;
                    break;
                }
                break;
            }
        }
    }
    //	cout<<"Calc";
    if(hi%lo==0){
        cout<<hi/lo;
    }else{
        int gcd=GCD(hi,lo);
        cout<<hi/gcd<<"/"<<lo/gcd;
    }
    return 0;
}
