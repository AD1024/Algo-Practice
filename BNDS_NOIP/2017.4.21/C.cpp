#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

struct Node{
    double y,k;
};

Node tree[(1000010+200000)<<2];
double ans;int N,M;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define Mid(x,y) (x+y) >> 1
#define INF 0x3f3f3f3f
#define SIFT 1000001

void update(int x,int l,int r,int x1,int x2,double y,double k){
    if(l == x1 && r == x2){
        if(l==r||(double)(tree[x].y-y)*(tree[x].y+(r-l)*tree[x].k-y-(r-l)*k)>0.0){
            if(y>tree[x].y) tree[x].y=y,tree[x].k=k;
            return;
        }
        int mid=Mid(l,r);
        int a=(double)tree[x].y+(mid-l)*tree[x].k;
        int b=(double)y+(mid-l)*k;
        if(b>a){
            swap(tree[x].y,y),swap(tree[x].k,k);
        }
        if((tree[x].y-y)*(a-b)>0){
            if(b>a){
                update(rson(x),mid+1,r,mid+1,x2,y+k*(mid-x1+1),k);
            }else{
                update(rson(x),mid+1,r,mid+1,x2,y+k*(mid-x1+1),k);
            }
        }else{
            update(lson(x),l,mid,x1,mid,y,k);
        }
        return;
    }
    int mid=Mid(l,r);
    if(x2<=mid)update(lson(x),l,mid,x1,x2,y,k);
    else if(x1>mid)update(rson(x),mid+1,r,x1,x2,y,k);
    else{
        update(lson(x),l,mid,x1,mid,y,k);
        update(rson(x),mid+1,r,mid+1,x2,y+k*(mid-x1+1),k);
    }
}

void getAns(int x,int l,int r,int y){
    ans=max(ans,tree[x].y+(y-l)*tree[x].k);
    if(l == r){
        return;
    }
    int mid=Mid(l,r);
    if(y<=mid) getAns(lson(x),l,mid,y);
    else getAns(rson(x),mid+1,r,y);
}

inline int read(){
    int a = 0;
    int flag = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){
        if(ch == '-') flag = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        a = a*10+ch-'0';ch = getchar();
    }
    return a * flag;
}

inline void addLine(){
    int x,xx,y,yy;
    double k;
    x = read();y = read();
    xx = read();yy = read();
    x += SIFT; xx += SIFT;
    if(x > xx) swap(x,xx);
    if(x == xx && y > yy) swap(y,yy);
    if(x == xx){
        y = yy;
        k = 0;
    }else{
        k = (double)(yy-y)/(double)(xx-x);
    }
    update(1,1,(SIFT)*2,x,xx,y,k);
}

int main(){
    N = read();M=read();
    for(int i=0;i<1000010<<2;++i) tree[i].y = -INF;
    int x,xx,y,yy,k;
    for(int i=1;i<=N;++i){
        addLine();
    }
    int op,pos;
    for(int i=1;i<=M;++i){
        op = read();
        if(op){
            pos = read();
            pos += SIFT;
            ans=-INF;
            getAns(1,1,(SIFT)<<1,pos);
            if(ans == -INF) ans=0;
            printf("%.6lf\n",ans);
        }else{
           addLine();
        }
    }
    return 0;
}