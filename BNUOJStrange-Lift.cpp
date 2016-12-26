#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 10001
#define INF 0xfffff

bool vis[MAXN];
int dist[MAXN];
queue<int> q;
int g[310][310];
int N;
int u,d;
inline void init(){
	cin>>u>>d;
	int v;
	memset(g,INF,sizeof(g));
	for(int i=1;i<=N;++i){
		vis[i]=false;
		dist[i]=INF;
		cin>>v;
		if(i+v<=N){
			g[i][i+v]=1;
		}
		if(i-v>=1){
			g[i][i-v]=1;
		}
	}
}
//N<=200 

inline void spfa(){
	vis[u]=true;
	dist[u]=0;
	q.push(u);
	int k;
	while(q.size()){
		k=q.front();
		q.pop();
		vis[k]=true;
		for(int i=1;i<=N;++i){
			if(dist[k]+g[k][i]<dist[i]){
				dist[i]=dist[k]+g[k][i];
				if(!vis[i]){
					vis[i]=true;
					q.push(i);
				}
			}
		}
		vis[k]=false;
	}
}

int main(){
	while(cin>>N){
		if(!N) break;
		init();
		spfa();
		cout<<dist[d]<<'\n';
	}
	return 0;
}