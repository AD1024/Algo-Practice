#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Edge{
	int u,v,w;
	Edge(int uu,int vv,int ww){
		u=uu;
		v=vv;
		w=ww;
	}
	Edge(){}
}e[200001];
int fa[200001];
int EID=0;
int N,M;

inline void init(){
	for(int i=1;i<=N;++i){
		fa[i]=i;
	}
}

inline int Find(int x){
	int r=x;
	while(r!=fa[r]) r=fa[r];
	int j;
	while(x!=r){
		j=fa[x];
		fa[x]=r;
		x=j;
	}
	return x;
}

inline void Union(int x,int y){
	int fx=Find(x);
	int fy=Find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}

inline void addEdge(int u,int v,int w){
	e[EID]=Edge(u,v,w);
	e[EID]=Edge(v,u,w);
	EID++;
}

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

inline int Kruskal(){
	init();
	sort(e,e+EID,cmp);
	int ans=0;
	for(int i=0;i<EID;++i){
		if(Find(e[i].u)!=Find(e[i].v)){
			ans+=e[i].w;
			Union(e[i].u,e[i].v);
		}
	}
	return ans;
}

int main(){
	cin>>N>>M;
	int u,v,w;
	while(M--){
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	cout<<Kruskal();
	return 0;
}