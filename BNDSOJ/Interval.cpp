#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

struct Edge{
	int v,w;
	int Next;
};

Edge e[500100];
int First[50100];
queue<int> q;
int dist[50100];
bool vis[50100];
int EID=1;
int from=0x3f3f3f3f,to=-0x3f3f3f3f;
int N;

inline void init(){
	memset(dist,-0x3f3f3f,sizeof(dist));
}

inline void AddEdge(int u,int v,int w){
	e[EID].Next=First[u];
	e[EID].v=v;
	e[EID].w=w;
	First[u]=EID++;
}

inline void SPFA(int s){
	vis[s]=true;
	dist[s]=0;
	q.push(s);
	int k;
	while(!q.empty()){
		k=q.front();q.pop();
		vis[k]=false;
		for(int i=First[k];i;i=e[i].Next){
			int v=e[i].v;
			if(dist[v]<dist[k]+e[i].w){
				dist[v]=dist[k]+e[i].w;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	int u,v,w;
	init();
	for(int i=1;i<=N;++i){
		scanf("%d%d%d",&u,&v,&w);
		from=min(from,u);
		to=max(to,v+1);
		AddEdge(u,v+1,w);
	}
	for(int i=from;i<to;++i){
		AddEdge(i,i+1,0);
		AddEdge(i+1,i,-1);
	}
	SPFA(from);
	printf("%d\n",dist[to]);
	return 0;
}