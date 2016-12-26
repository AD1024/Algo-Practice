#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAXN 10001
int First[MAXN],Next[MAXN],v[MAXN];
int EID = 1;
int dist[MAXN];
int current[MAXN];
int N,M;

typedef long long ll;
ll w[MAXN];
inline void AddEdge(int F,int T,int W){
	Next[EID] = First[F];
	v[EID] = T;
	w[EID] = W;
	First[F] = EID++;
}

inline ll DFS(int u,int INF){
	ll ans,cost;
	ans=cost=0;
	if(u==N) return INF;
	for(int i=current[u];i;i=Next[i]){
		int t = v[i];
		if(dist[t]!=dist[u]+1) continue;
		ans=DFS(t,min(INF-cost,w[i]));
		w[i]-=ans;
		w[i^1]+=ans;
		if(w[i]) current[u]=i;
		cost+=ans;
		if(cost == INF) return INF;
	}
	if(!cost) dist[u]=-1;
	return cost;
}

inline bool BFS(){
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(1);
	int k;
	dist[1]=0;
	while(!q.empty()){
		k = q.front();q.pop();
		for(int i=First[k];i;i=Next[i]){
			if(dist[v[i]]<0 && w[i]>0){
				dist[v[i]]=dist[k]+1;q.push(v[i]);
			}
		}
	}
	return dist[N]>0;
}

inline void Dinic(){
	ll ans = 0;
	while(BFS()){
		for(int i=1;i<=N;++i){
			current[i]=First[i];
		}
		ans+=DFS(1,0x3f3f3f3f);
	}
	cout<<ans;
	return;
}

int main(){
	cin>>N>>M;
	for(int i=1;i<=M;++i){
		int f,t,k;cin>>f>>t>>k;
		AddEdge(f,t,k);
		AddEdge(t,f,0);
	}
	//puts("OOK");
	Dinic();
	return 0;
}