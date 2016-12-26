#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 201000
#define INF 0x3f3f3f3f
vector<int> g[MAXN];
vector<int> g1[MAXN];
bool vis[MAXN];bool ok[MAXN];
int N,M;int Out[MAXN];int dist[MAXN];
inline void AddEdge(int F,int T){
	g[F].push_back(T);
	g1[T].push_back(F);
}

void Find(int u){
	if(!ok[u]){
		ok[u]=true;
		for(int i=0;i<g1[u].size();++i){
			Find(g1[u][i]);
		}
	}
}

inline bool OK(int u){
	for(int i=0;i<g[u].size();++i){
		if(!ok[g[u][i]]) return false;
	}
	return true;
}

inline void SPFA(int s){
	memset(dist,INF,sizeof(dist));
	memset(vis,false,sizeof(vis));
	deque<int> q;
	q.push_front(s);
	vis[s]=true;int k;
	dist[s]=0;
	while(q.size()){
		k=q.front();q.pop_front();
		vis[k]=false;
		for(int i=0;i<g[k].size();++i){
			int v=g[k][i];
			if(OK(v)){
				if(dist[v]>dist[k]+1){
					dist[v]=dist[k]+1;
					if(!vis[v]){
						vis[v]=true;
						if(dist[v]<dist[k]){
							q.push_front(v);
						}else q.push_back(v);
					}
				}
			}
		}
	}
}

int main(){
	cin>>N>>M;int u,v;
	for(int i=1;i<=M;++i){
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
	}
	int s,t;
	cin>>s>>t;
	Find(t);
	SPFA(s);
	if(dist[t]==INF){
		puts("-1");
	}else{
		cout<<dist[t];
	}
	return 0;
}