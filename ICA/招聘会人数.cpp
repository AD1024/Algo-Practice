#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

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

int 

int main(){
	string a,b;
	cin>>a>>b;

}