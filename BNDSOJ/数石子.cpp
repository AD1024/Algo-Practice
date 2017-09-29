#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int fa[101000],dist[101000];

int N,M,K;

int Find(int x){
	if(x == fa[x]) return x;
	int t = Find(fa[x]);
	dist[x] += dist[fa[x]];
	fa[x] = t;
	return t;
}

inline void Union(int x,int y,int k){
	int fx = Find(x);
	int fy = Find(y);
	if(fx != fy){
		fa[fy] = x;
		dist[fy] = k-dist[y];
	}
}

inline bool SameSet(int x,int y){
	return Find(x) == Find(y);
}

int main(){
	scanf("%d%d%d", &N,&M,&K);
	for(int i=0;i<=N;++i){
		fa[i] = i;
	}
	for(int i=1;i<=M;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		Union(a-1,b,c);
	}
	while(K--){
		int a,b;
		scanf("%d%d",&a,&b);--a;
		if(SameSet(a,b)){
			printf("%d\n",dist[b] - dist[a]);
		}else{
			puts("UNKNOWN");
		}
	}
	return 0;
}