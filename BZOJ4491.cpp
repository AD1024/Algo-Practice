#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define MID(x,y) (x+y)>>1
#define lson(x) x<<1
#define rson(x) x<<1|1

const int N=50010;

struct Node{
    int lu,ru,ldown,rdown,lv,rv,len,mu,md;
}T[N<<2];

int n,x,y,a[N],Q;

inline Node update(Node a,Node b){
    Node ans;
    ans.len=a.len+b.len;
    ans.lv=a.lv;ans.rv=b.rv;
    ans.lu=a.lu;
    if (a.lu==a.len&&a.rv<=b.lv)
        ans.lu=a.len+b.lu;
    ans.ldown=a.ldown;
    if (a.ldown==a.len&&a.rv>=b.lv)
        ans.ldown=a.len+b.ldown;
    ans.ru=b.ru;
    if (b.ru==b.len&&b.lv>=a.rv)
        ans.ru=b.len+a.ru;
    ans.rdown=b.rdown;
    if (b.rdown==b.len&&b.lv<=a.rv)
        ans.rdown=b.len+a.rdown;
    ans.mu=max(a.mu,b.mu);
    if (a.rv<=b.lv)
        ans.mu=max(ans.mu,a.ru+b.lu);
    ans.md=max(a.md,b.md);
    if (a.rv>=b.lv)
        ans.md=max(ans.md,a.rdown+b.ldown);
    return ans;
}

void build(int k,int l,int r){
    int mid=MID(l,r);
    if (l==r){
        T[k].lv=T[k].rv=a[l];
        T[k].lu=T[k].ru=T[k].ldown=T[k].rdown=T[k].len=T[k].mu=T[k].md=1;
        return;
    }
    build(lson(k),l,mid);
    build(rson(k),mid+1,r);
    T[k]=update(T[k<<1],T[rson(k)]);
}

inline Node query(int k,int l,int r,int Lson,int Rson){
    if (l==Lson && r==Rson)
        return T[k];
    int mid=MID(l,r);
    if (Rson<=mid) return query(lson(k),l,mid,Lson,Rson);
    else if (mid<Lson) return query(rson(k),mid+1,r,Lson,Rson);
    else return update(query(lson(k),l,mid,Lson,mid),query(rson(k),mid+1,r,mid+1,Rson));
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&Q);
    build(1,1,n);
    while(Q--){
        scanf("%d%d",&x,&y);
        Node a=query(1,1,n,x,y);
        printf("%d\n",max(a.mu,a.md));  
    }  
}