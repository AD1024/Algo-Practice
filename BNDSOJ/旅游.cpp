#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXE 110000
#define MAXV 20100
#define MAXQ 10100

struct Edge{
	int u, v, w;
	void init(){
		scanf("%d%d%d", &u, &v, &w);
	}
};

struct Query{
	int x, id;
	void init(int i) {
		id=i;
		scanf("%d", &x);
	}
};

Edge e[MAXE];

Query q[MAXQ];

int fa[MAXV];
int sum[MAXV];
int ans;
int out[MAXQ];

int N,M,Q;

bool ecmp(Edge a, Edge b){
	return a.w < b.w;
}

bool qcmp(Query a, Query b){
	return a.x < b.x;
}

int Find(int x) {
	return x^fa[x] ? fa[x]=Find(fa[x]) : x;
}

inline void Union(int x, int y) {
	int fx = Find(x);
	int fy = Find(y);
	if(fx ^ fy) {
		int a = sum[fx];int b = sum[fy];
		ans -= (a-1)*a;
		ans -= (b-1)*b;
		sum[fy] += sum[fx];
		ans += (sum[fy]-1) * sum[fy];
		sum[fx] = 0;
		fa[fx] = fy;
	}
}

inline void work(){
	int c = 0;
	for(int i=0;i<Q;++i){
		while(c < M && e[c].w <= q[i].x) {
			Union(e[c].u, e[c].v);
			++c;
		}
		out[q[i].id] = ans;
	}
	for(int i=0;i<Q;++i){
		printf("%d\n", out[i]);
	}
}

inline void init(){
	scanf("%d%d%d", &N, &M, &Q);
	ans = 0;
	for(int i=1;i<=N;++i) {
		fa[i] = i;
		sum[i] = 1;
	}
	for(int i=0;i<M;++i) {
		e[i].init();
	}
	sort(e, e+M, ecmp);
	for(int i=0;i<Q;++i) {
		q[i].init(i);
	}
	sort(q, q+Q, qcmp);
}

int main(){
	int T;scanf("%d", &T);
	while(T--){
		init();
		work();
	}
	return 0;
}