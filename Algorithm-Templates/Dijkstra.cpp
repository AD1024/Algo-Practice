#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

#define MAXN 1001
#define INF 0x3f3f3f3f

struct Edge{
	int v,w;
	Edge(){}
	Edge(int vv,int ww){
		v=vv;w=ww;
	}
};
vector<Edge> g[MAXN];
int dist[MAXN];
bool vis[MAXN];
int N,M;

inline void init(){
	memset(vis,false,sizeof(vis));
	memset(dist,INF,sizeof(dist));
}

inline void AddEdge(int u,int v,int w){
	g[u].push_back(Edge(v,w));
	g[v].push_back(Edge(u,w));
}

inline void Dijkstra(int start){
	vis[start]=true;
	dist[start]=0;
	for(int i=0;i<g[start].size();++i){
		dist[g[start][i].v]=g[start][i].w;
	}
	int MIN;
	int pos=start;
	for(int i=1;i<N;++i){
		MIN=0x3f3f3f3f;
		for(int i=0;i<g[pos].size();++i){
			if(!vis[g[pos][i].v] && MIN>dist[g[pos][i].v]){
				start=g[pos][i].v;
				MIN=dist[start];
			}
		}
		vis[start]=true;
		pos=start;
		for(int i=0;i<g[pos].size();++i){
			if(!vis[g[pos][i].v] && dist[g[pos][i].v]>dist[pos]+g[pos][i].w){
				dist[g[pos][i].v]=dist[pos]+g[pos][i].w;
			}
		}
	}
}

int main(){
	cin>>N>>M;
	int u,v,w;
	init();
	while(M--){
		cin>>u>>v>>w;
		AddEdge(u,v,w);
	}
	cin>>u;
	Dijkstra(u);
	for(int i=1;i<=N;++i){
		printf("%d ",dist[i]);
	}
	return 0;
}