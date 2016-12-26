#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 30010
#define INF 0xffffff
#define pb(x) push_back(x)
struct Edge{
	int u,v,w;
};

vector<Edge> g[MAXN];
bool used[MAXN];
int T,M,N;
bool found=false;
int dist[MAXN];

inline void reset(){
	for(int i=1;i<=N;++i){
		dist[i]=INF;
		used[i]=false;
		g[i].clear();
	}
	found=false;
}

bool tag=false;
bool dfs(int idx){
	used[idx]=true;
	for(int i=0;i<g[idx].size();++i){
		if(!used[g[idx][i].v]){
			if(tag) return 0;
			dist[g[idx][i].v]=dist[idx]+g[idx][i].w;
			dfs(g[idx][i].v);
		}else{
			if(dist[g[idx][i].v]!=dist[idx]+g[idx][i].w){
				tag=true;
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	cin>>T;
	int U,V,W;
	while(T--){
		cin>>N>>M;
		reset();
		Edge n,m;
		for(int i=1;i<=M;++i){
			cin>>U>>V>>W;
			n.u=U;
			n.v=V;
			n.w=W;
			m.u=V;m.v=U;m.w=-W;
			g[U].pb(n);
			g[V].pb(m);
		}
		for(int i=1;i<=N;++i){
			if(used[i]) continue;
			tag=false;
			dist[i]=0;
			if(!dfs(i)){
				puts("Bessie is blind.");
				found=true;
				break;
			}
		}
		if(!found)
			puts("Bessie's eyes are good");
	}
	return 0;
}
