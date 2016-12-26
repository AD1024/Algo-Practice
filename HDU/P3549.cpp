#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 100010
#define clear(x) memset(x,0,sizeof(x))
typedef long long ll;

int First[MAXN],Next[MAXN],v[MAXN];
ll w[MAXN];
int EID = 1;
int dist[MAXN];
int N,M,T;int current[MAXN];
int CASE=0;

inline void AddEdge(int F,int T,int W){
	Next[EID]=First[F];
	v[EID]=T;
	w[EID]=W;
	First[F]=EID++;
}

ll DFS(int u,int INF){
	ll ans,cost;
	ans=cost=0;
	if(u==N) return INF;
	for(int i=current[u];i;i=Next[i]){
		int t=v[i];
		if(dist[t]!=dist[u]+1) continue;
		ans=DFS(t,min(INF-cost,w[i]));
		w[i]-=ans;
		w[i^1]+=ans;
		if(w[i]) current[u]=i;
		cost+=ans;
		if(cost==INF) return INF;
	}
	if(!cost) dist[u]=-1;
	return cost;
}

inline bool BFS(){
	queue<int> q;
	memset(dist,-1,sizeof(dist));
	q.push(1);
	dist[1]=0;
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=First[k];i;i=Next[i]){
			if(dist[v[i]]<0 && w[i]>0){
				dist[v[i]]=dist[k]+1;
				q.push(v[i]);
			}
		}
	}
	return dist[N]>0;
}

inline void Dinic(){
	ll ans=0;
	while(BFS()){
		for(int i=1;i<=N;++i){
			current[i]=First[i];
		}
		ans+=DFS(1,0x3f3f3f3f);
	}
	cout<<"CASE "<<CASE<<":"<<" "<<ans<<"\n";
}

int main(){
	cin>>T;
	int a,b,c;
	ios::sync_with_stdio(false);
	while(T--){
		cin>>N>>M;
		clear(First);
		clear(Next);
		clear(w);clear(v);
		for(int i=1;i<=M;++i){
			cin>>a>>b>>c;
			AddEdge(a,b,c);
			AddEdge(b,a,0);
		}
		++CASE;
		Dinic();
	}
}