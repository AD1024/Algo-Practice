#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define v(x) tree[x].v
#define p(x) tree[x].pos

struct Node{
    int v,pos;
};

Node tree[1010000<<2];

int ans[1010000];

int a[1010000];

int maxv, cpos;

int N,M,L,R;

inline void Maintain(int x){
    if(v(lson(x)) > v(rson(x))) {
        v(x) = v(lson(x));
        p(x) = p(lson(x));
    }else{
        v(x) = v(rson(x));
        p(x) = p(rson(x));
    }
}

inline void build() {
    for(M=1;M<=N+R;M<<=1);
    for(register int i=M+1;i<=M+N+R;++i) {
        v(i) = a[i-M];
        p(i) = i-M;
    }
    for(register int i=M-1;i;--i) {
        Maintain(i);
    }
}

inline void query(int l, int r) {
    int ans = -0x3f3f3f3f;
    int pp = 1;
    for(l=l+M-1,r=r+M+1;l^r^1;l>>=1, r>>=1) {
        if(~l&1){
            if(v(l^1) > ans) {
                ans = v(l^1);
                pp = p(l^1);
            }
        }
        if(r^1) {
            if(v(r^1) > ans) {
                ans = v(r^1);
                pp = p(r^1);
            }
        }
    }
    maxv = ans;
    cpos = pp;
}

inline void update(int pos, int value) {
    pos += M;
    v(pos) = value;
    for(pos>>=1;pos;pos>>=1) Maintain(pos);
}

inline void work(){
    for(int i=N+1;i;--i){
        query(i+L, i+R);
        ans[i] = ans[cpos] + a[i];
        update(i, ans[i]);
    }
}

int main(){
    scanf("%d%d%d", &N, &L, &R);
    N+=2;
    a[1] = 0;
    for(int i=2;i<=N;++i) scanf("%d", &a[i]);
    build();
    work();
    printf("%d", ans[1]);
    return 0;
}