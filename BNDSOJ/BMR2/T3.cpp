#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int N;
inline int read(){
    int a = 0;
    int f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){
        if(ch == '-') f = -1;ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        a = a*10+ch-'0';
        ch = getchar();
    }
    return a * f;
}

struct Node{
    int lson,rson;
    int size;
    int v;
    int x;
};
#define lson(x) x<<1
#define rson(x) x<<1|1

Node tree[101000<<2];
int ans[101000<<2];

inline void Maintain(int i){
    tree[i].size = tree[lson(i)].size + tree[rson(i)].size;
}

void build(int rt, int l,int r){
    if(l == r){
        tree[rt].lson = -1;
        tree[rt].rson = -1;
        tree[rt].v = l;
        tree[rt].size = 1;
    }else{
        int mid = (l+r) >> 1;
        tree[rt].lson = lson(rt);
        tree[rt].rson = rson(rt);
        build(lson(rt), l ,mid);
        build(rson(rt), mid+1,r);
        Maintain(rt);
    }
}

void update(int rt,int s,int v){
    if(tree[rt].lson == tree[rt].rson && tree[rt].lson == -1){
        tree[rt].x = v;
        ans[tree[rt].v] = v;
        tree[rt].size = 0;
    }else{
        if(tree[lson(rt)].size >= s){
            update(lson(rt), s, v);
        }else{
            update(rson(rt), s-tree[lson(rt)].size, v);
        }
        Maintain(rt);
    }
}

int main(){
    scanf("%d", &N);
    build(1,1,N);int ai;
    for(int i=1;i<=N;++i){
        scanf("%d", &ai);
        update(1, ai, i);
    }
    for(int i=1;i<=N;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}