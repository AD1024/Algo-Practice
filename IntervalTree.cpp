#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAXN 10001

struct Node{
	int l,r,v;
}T[MAXN];
int fa[MAXN];
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a

inline void pushup(int x){
	T[x].v=MAX(T[x<<1].v,T[(x<<1)+1].v);
}


void build(int l,int r,int idx){
	T[idx].l=l;
	T[idx].r=r;
	T[idx].v=0;
	if(l==r) {fa[l]=idx;return;}
	build(l,(l+r)>>1,idx<<1);
	build(1+((l+r)>>1),r,(idx<<1)+1);
}

void update(int id,int idx,int add){
	if(T[idx].l==T[idx].r){
		T[idx].v+=add;
		return;
	}
	int m=(T[idx].l+T[idx.r])>>1;
	if(id>m){
		update(id,idx<<1|1,add);
	}else{
		update(id,idx<<1,add);
	}
	T[idx].v=MAX(T[idx<<1].v,T[idx<<1|1].v);
}
int	query(int l,int r,int idx){
	
}

int main(){

}
