#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node{
    int son[2];
    int size;
    int w;
    int fix;int v;
    Node(){
        son[0] = son[1] = 0;
    }
};

Node t[10100<<2];
int cnt=0;
int root = 0;

#define lson(x) t[x].son[0]
#define rson(x) t[x].son[1]

inline void maintain(int rt){
    t[rt].size = t[lson(rt)].size + t[rson(rt)].size;
}

inline void rotate(int &rt,int pos){
    int tmp = t[rt].son[pos];
    t[rt].son[pos] = t[tmp].son[pos^1];
    t[tmp].son[pos^1] = rt;
    maintain(rt);
    rt = tmp;
}

void insert(int &rt, int v){
    if(rt == 0){
        ++cnt;
        rt = cnt;
        t[rt].w = t[rt].size = 1;
        t[rt].fix = rand();
        t[rt].v = v;
    }else{
        if(t[rt].v == v){
            t[rt].w ++;
        }else{
            int pos = t[rt].v < v;
            insert(t[rt].son[pos], v);
            if(t[rt].fix < t[t[rt].son[pos]].fix){
                rotate(rt, pos);
            }
        }
    }
}

void remove(int &rt, int v){
    if(rt == 0) return;
    else{
        if(t[rt].v == v){
            if(t[rt].w > 1){
                t[rt].w--;t[rt].size--;return;
            }else{
                if(lson(rt) * rson(rt) == 0) rt = lson(rt) + rson(rt);
                else{
                    int pos = t[lson(rt)].fix < t[rson(rt)].fix;
                    rotate(rt, pos);
                    remove(rt, v);
                }
            }
        }else if(t[rt].v < v){
            t[rt].size -- ;
            remove(rson(rt), v);
        }else{
            t[rt].size -- ;
            remove(lson(rt), v);
        }
    }
}

void pre(int rt){
    if(rt == 0) return;
    else{
        pre(lson(rt));
        cout<<t[rt].v<<" ";
        pre(rson(rt));
    }
}

int main(){
    srand(time(NULL));
    int N;cin>>N;
    int v;
    for(int i=1;i<=N;++i){
        cin>>v;
        insert(root, v);
    }
    pre(root);
    return 0;
}