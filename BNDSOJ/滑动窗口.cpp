#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

#define rson(x) x<<1|1
#define lson(x) x<<1
#define MX(x) tree[x].d[0]
#define MI(x) tree[x].d[1]
#define MAXN 1001000
struct Node{
	int d[2];
};

Node tree[MAXN<<2];

int N,M,K;

int ans[2][MAXN+10100];
int cur[2];

inline void Maintain(int rt) {
	MX(rt) = max(MX(lson(rt)), MX(rson(rt)));
	MI(rt) = min(MI(lson(rt)), MI(rson(rt)));
}

inline int read(){
	char ch = getchar();
	int a = 0;
	bool flag = false;
	while(ch > '9' || ch < '0') {
		if(ch == '-') flag = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		a = a * 10 + ch - '0';
		ch = getchar();
	}
	return flag?-a:a;
}

inline void build(){
	for(M=1;M<=N;M<<=1);
	int d;
	for(register int i=M+1;i<=M+N;++i){
		d = read();
		MI(i) = MX(i) = d;
	}
	for(register int i=M-1;i;--i)
		Maintain(i);
}

inline void query(int l,int r) {
	int minm = 0x3f3f3f3f;
	int maxn = -0x3f3f3f3f;
	for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1) {
		if(~l&1){
			minm = min(MI(l^1), minm);
			maxn = max(MX(l^1), maxn);
		}
		if(r&1){
			minm = min(MI(r^1), minm);
			maxn = max(MX(r^1), maxn);
		}
	}
	ans[0][cur[0]++] = minm;
	ans[1][cur[1]++] = maxn;
}

int main(){
	N = read();K = read();
	build();
	for(register int i=K;i<=N;++i){
		query(i-K+1, i);
	}
	for(register int i=0;i<cur[0];++i){
		printf("%d ",ans[0][i]);
	}
	puts("");
	for(register int j=0;j<cur[1];++j){
		printf("%d ",ans[1][j]);
	}
	return 0;
}