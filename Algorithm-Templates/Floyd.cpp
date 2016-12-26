#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 110
#define INF 0x3f3f3f3f
// Floyd can calculate shortest pathes between each vertice, thus it maintains a high complexity O(N^3)

int g[MAXN][MAXN];
int N,M;
inline void init(){
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(i==j){
				g[i][j]=0;
			}else{
				g[i][j]=INF;
			}
		}
	}
}

inline void Addedge(int u,int v,int w){
	g[u][v]=w;
	// If it's undirected graph, add the line below me
	g[v][u]=w;
}

inline void Floyd(){
	for(int k=1;k<=N;++k){
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(g[i][j]>g[i][k]+g[k][j]){
					g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
}

int main(){
	cin>>N>>M;
	init();
	while(M--){
		int u,v,w;
		cin>>u>>v>>w;
		Addedge(u,v,w);
	}
	Floyd();
	// To look up the shortest path between u and v, just use g[u][v]
	cin>>M;
	while(M--){
		int u,v;
		cin>>u>>v;
		printf("%d\n",g[u][v]);
	}
	return 0;
}