#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 10010
#define INF 0x3f3f3f3f
struct Edge{
	int v,w;
	Edge(){}
	Edge(int vv,int ww){
		v=vv;
		w=ww;
	}
};

vector<Edge> g[MAXN];
bool vis[MAXN];
int dist[MAXN];
int N,M,s;
inline void init(){
	for(int i=0;i<=N;++i){
		dist[i]=2147483647;
		vis[i]=false;
	}
}

inline void addEdge(int u,int v,int w){
	g[u].push_back(Edge(v,w));
}

inline void SPFA(int s){
	int k,v;
	queue<int> q;
	q.push(s);
	dist[s]=0;
	while(q.size()){
		k=q.front();q.pop();
		vis[k]=true;
		for(int i=0;i<g[k].size();++i){
			v=g[k][i].v;
			if(g[k][i].w+dist[k]<dist[v]){
				dist[v]=g[k][i].w+dist[k];
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
		vis[k]=false;
	}
}

int main(){
	cin>>N>>M>>s;
	init();
	int u,v,w;
	while(M--){
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	SPFA(s);
	for(int i=1;i<=N;++i){
		printf("%d ",dist[i]);
	}
	return 0;
}