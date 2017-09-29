#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node{
    int Max,Min;
};
Node tree[101000<<1];
int M,N;int Hi;

#define lson(x) x<<1
#define rson(x) x<<1|1

inline void Maintain(){
    for(int i=M-1;i;--i){
        tree[i].Max = max(tree[lson(i)].Max, tree[rson(i)].Max);
        tree[i].Min = min(tree[lson(i)].Min, tree[rson(i)].Min);
    }
}

inline void build(){
    for(M=1;M<=N+1;M<<=1);
    for(int i=M+1;i<=M+N;++i){
        scanf("%d", &tree[i].Max);
        tree[i].Min = tree[i].Max;
    }
    Maintain();
}
int maxn,minm;
inline bool query(int l,int r){
    maxn = -0x3f3f3f3f;
    minm = 0x3f3f3f3f;
    for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
        if(~l&1){
            cout<<"l:"<<l<<'\n';
            maxn = max(maxn, tree[l^1].Max);
            minm = min(minm, tree[l^1].Min);
        }
        if(r&1){
            cout<<"r:"<<r<<'\n';
            maxn = max(maxn, tree[r^1].Max);
            minm = min(minm, tree[r^1].Min);
        }
    }
    return maxn-minm <= Hi;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d", &N, &Hi);
        build();
        int Q;scanf("%d", &Q);
        while(Q--){
            int l,r;scanf("%d%d",&l, &r);
            if(query(l,r)){
                puts("YES");
            }else{
                puts("NO");
            }
        }
    }
    return 0;
}