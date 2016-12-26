#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
bool vis[10001];
int dist[10001];

int M,N;

struct Edge{
	int v,w;
	void init(int V,int W){
		v=V;
		w=W;
	}
};

vector<Edge> g[10001];

inline void addEgde(int u,int v,int w){
	Edge e;
	e.init(v,w);
	g[u].push_back(e);
}

inline void init(){
	for(int i=0;i<=N;++i){
		dist[i]=0;
		vis[i]=false;
	}
}

inline void spfa(){
	int s=1;
	dist[s]=0;
	vis[s]=true;
	q.push(s);
	int k,v;
	while(q.size()){
		k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=0;i<g[k].size();++i){
			v=g[k][i].v;
			if(dist[v]<dist[k]+g[k][i].w){
				dist[v]=dist[k]+g[k][i].w;
				if(!vis[i]){
					vis[i]=true;
					q.push(i);
				}
			}
		}
	}
	
}

int main(){
	cin>>N>>M;
	int u,v,w;
	for(int i=0;i<M;++i){
		cin>>u>>v>>w;
		addEgde(u,v,w);
		addEgde(v,u,w);
	}
	spfa();
	cout<<dist[N];
	return 0;
}