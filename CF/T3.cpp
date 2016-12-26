#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
#define MAXN 5010
struct Edge{
	int v,w;
	Edge(){}
	Edge(int vv,int ww){
		v=vv;
		w=ww;
	}
};
vector<Edge> g[5010];
bool vis[MAXN];
int path[MAXN];
stack<int> s;
int N,M,T;
int p[MAXN],dp[MAXN];

inline void init(){
	memset(p,-1,sizeof(p));
	for(int i=1;i<=N;++i){
		dp[i]=1;
	}
}

void dfs(int u,int tot){
	if(u==N) return;
	vis[u]=true;
	int v;
	for(int i=0;i<g[u].size();++i){
		v=g[u][i].v;
		if(tot+g[u][i].w<=T){
			if(!vis[v]){
				dfs(v,tot+g[u][i].w);
				if(dp[u]<dp[v]+1){
					dp[u]=dp[v]+1;
					p[u]=v;
				}
			}
		}
	}
}

inline void addEdge(int u,int v,int w){
	g[u].push_back(Edge(v,w));
	//g[v].push_back(Edge(u,w));
}

int main(){
	cin>>N>>M>>T;
	init();
	for(int i=0;i<M;++i){
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	for(int i=1;i<N;++i){
		if(!vis[i]){
			dfs(i,0);
		}
	}
	int mx=-1;
	int place;
	for(int i=1;i<N;++i){
		if(dp[i]>mx){
			mx=dp[i];
			place=i;
		}
	}
	cout<<mx<<"\n";
	while(place!=-1){
		cout<<place<<" ";
		place=p[place];
	}
	return 0;
}