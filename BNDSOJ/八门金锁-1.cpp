#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

#define fi first
#define se second
#define MAXN 101000
#define INF 0x3f3f3f3f3f
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef pair<int,long long> pi;

struct Edge{
	int v;
	ll w;
	int next;
};

Edge e[MAXN];
ll ans;
int First[MAXN];
ll dist[MAXN];
ll f[MAXN],ff[MAXN];
bool vis[MAXN],rem[MAXN];
int EID;
int N,M,U,V,S;

priority_queue<pi,vector<pi>, greater<pi> > q;

inline void addEdge(int u,int v,int w){
	e[EID].next = First[u];
	e[EID].v = v;
	e[EID].w = w;
	First[u] = EID++;
}

inline bool ok(int value){
	if(f[U] > value or f[V] > value) return false;
	for(int i=1;i<=N;++i){
		dist[i]=INF;
		vis[i] = false;
		rem[i] = false;
		if(f[i] > value){
			rem[i]=true;
		}
	}
	dist[U] = 0;
	q.push(mp(dist[U], U));
	int k,v;
	while(!q.empty()){
		k = q.top().se;
		q.pop();
		if(vis[k]) continue;
		vis[k] = true;
		for(int i=First[k];~i;i=e[i].next){
			v = e[i].v;
			if(rem[v]) continue;
			if(dist[v] > dist[k] + e[i].w){
				dist[v] = dist[k] + e[i].w;
				q.push(mp(dist[v], v));
			}
		}
	}
	return dist[V] <= S;
}
int main(){
	memset(First, -1,sizeof(First));
	ios::sync_with_stdio(false);
	cin>>N>>M>>U>>V>>S;
	for(int i=1;i<=N;++i) cin>>f[i];
	int a,b;ll c;
	for(int i=1;i<=M;++i){
		cin>>a>>b>>c;
		addEdge(a,b,c);
		addEdge(b,a,c);
	}
	memcpy(ff, f, sizeof(f));
	sort(ff+1, ff+1+N);
	// for(int i=1;i<=N;++i) cout<<ff[i]<<" ";
	int l,r;
	l = 1,r=N;
	if(ok(ff[N])){
		int mid;
		while(l<r){
			mid = (l+r)>>1;
			if(ok(ff[mid])){
				r = mid;
			}else{
				l = mid+1;
			}
		}
		cout<<ff[l];
	}else{
		cout<<"-1";
	}
	return 0;
}