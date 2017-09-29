#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <list>
using namespace std;

struct Node{
    int lson,rson,w,v,p;
}tree[1010000<<2];

int N;
int a[201000];
int ans[201000];

#define lson(x) x<<1
#define rson(x) x<<1|1
#define Mid(x,y) (x+y)>>1 
#define v(x) tree[x].v
#define w(x) tree[x].w

inline void Maintain(int x){
    w(x) = w(lson(x)) + w(rson(x));
}

void build(int rt,int l,int r){
    tree[rt].lson = l;
    tree[rt].rson = r;
    if(l == r){
        tree[rt].p = l;
        tree[rt].w = 1;
        return;
    }
    int mid = Mid(l,r);
    build(lson(rt), l, mid);
    build(rson(rt), mid+1, r);
    Maintain(rt);
}

void insert(int rt, int w,int v){
    // printf("%d\n", rt);
    if(tree[rt].lson == tree[rt].rson){
        tree[rt].v = v;
        tree[rt].w = 0;
        ans[tree[rt].p] = v;
    }else{
        // cout<<w(rt)<<endl;
        if(w(lson(rt)) >= w){
            insert(lson(rt), w, v);
        }else{
            insert(rson(rt), w - w(lson(rt)), v);
        }
        Maintain(rt);
    }
}

int main(){
    scanf("%d", &N);
    build(1,1,N);
    for(int i=1;i<=N;++i) scanf("%d", &a[i]);
    for(int i=N;i>=1;--i){
        insert(1, a[i]+1, i);
    }
    for(int i=1;i<=N;++i) 
        cout<<ans[i]<<" ";
    return 0;
}