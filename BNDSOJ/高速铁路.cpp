#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define lson(x) x<<1
#define rson(x) x<<1|1
#define MID(x,y) (x+y)>>1
#define bk break
typedef long long ll;
typedef void V;


ll A[100010],B[100010],C[100010];
int N,K;
int q;
int M,T;

inline long long read(){
    char ch;
    bool flag = false;
    int a=0;
    while(!((((ch=getchar())>='0') && (ch<='9')) || (ch=='-')));
    if(ch!='-'){
        a *= 10;
        a += ch - '0';
    }
    else{
        flag = true;
    }
    while(((ch=getchar())>='0')&& (ch<='9')){
        a *= 10;
        a += ch - '0';
    }
    if(flag){
        a = -a;
    }
    return a;
}
ll G[100010<<1];
ll num[100010<<1], sum[100010<<1], add[100010<<1], v;

void pushDown(int i, int l, int r) {
    if(add[i] != 0) {
        int mid=MID(l,r);
        add[lson(i)]+=add[i];
        sum[lson(i)]+=(mid-l+1)*add[i];
        add[rson(i)]+=add[i];
        sum[rson(i)]+=(r-mid)*add[i];
        add[i]=0;
    }
}

void update(int i, int l, int r, int ql, int qr, int val) {
    if(l>qr || ql>r)
        return;
    if(l>=ql && r<=qr){
        sum[i]+=(r-l+1)*val;
        add[i]+=val;
        return ;
    }
    pushDown(i,l,r);
    int mid=MID(l,r);
    update(lson(i),l,mid,ql,qr,val);
    update(rson(i),mid+1,r,ql,qr,val);
    sum[i]=sum[lson(i)]+sum[rson(i)];
}

ll query(int i,int l,int r,int ql,int qr) {
    if(l>qr || ql>r)
        return 0;
    if(l>=ql && r<=qr)
        return sum[i];
    pushDown(i,l,r);
    int mid=MID(l,r);
    return query(lson(i),l,mid,ql,qr)
    + query(rson(i),mid+1,r,ql,qr);
}

int main(){
    N=read();M=read();
    for(int i=1;i<=M;++i){
        G[i]=read();
    }
    for(int i=1;i<M;++i){
        int b,e;
        b=G[i];e=G[i+1];
        if(b>e) swap(b,e);
        update(1,1,N,b,e-1,1);
    }
    long long Ai,Bi,Ci;
    long long ans=0;
    for(int i=1;i<=N-1;++i){
        Ai=read();Bi=read();Ci=read();
        ll t = query(1,1,N,i,i);
        ans+=min(Ai*t,Bi*t+Ci);
    }
    cout<<ans;
    return 0;
}