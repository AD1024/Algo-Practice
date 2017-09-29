#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Edge{
	int u,v,w;
	void init(){
		scanf("%d%d%d", &u, &v, &w);
	}
};

Edge e[1010];

int fa[55];
int N,M;
inline void init(){
	for(int i=1;i<=N;++i) fa[i] = i;
}

inline int Find(int x){
	while(x != fa[x]) x = fa[x];
	return x;
}

inline void Union(int x,int y){
	int fx = Find(x);
	int fy = Find(y);
	if(fx != fy){
		fa[fx] = fy;
	}
}

inline bool SameSet(int x,int y){
	return Find(x) == Find(y);
}

inline bool cmp(Edge a, Edge b){
	return a.w<b.w;
}

inline int work(){
	sort(e+1, e+1+M, cmp);
	int ans = 0;
	for(int i=1;i<=M;++i){
		if(!SameSet(e[i].u, e[i].v)){
			ans += e[i].w;
			Union(e[i].u, e[i].v);
		}
	}
	return ans;
}

int main(){
	scanf("%d%d", &N, &M);
	init();
	for(int i=1;i<=M;++i) e[i].init();
	printf("%d", work());
	return 0;
}