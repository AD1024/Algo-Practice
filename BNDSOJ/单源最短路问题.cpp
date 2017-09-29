#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f
#define fi First
#define se second
#define mmp(x, y) make_pair(x, y)

struct Edge{
	int v,w,next;
};

typedef pair<int,int> pi;

Edge e[1010000];

int First[1010000];

int N,M,EID;

bool vis[1010000];
int dist[1010000];

priority_queue<pi, vector<pi>, greater<pi> > q;

inline void init(){
	memset(First, -1, sizeof(First));
}

inline void addEdge(int u,int v,int w) {
	e[EID].next = First[u];
	e[EID].v = v;
	e[EID].w = w;
	First[u] = EID++;
}

inline int Dij(int s, int t){
	memset(vis, false, sizeof(vis));
	for(int i=1;i<=N;++i){
		dist[i] = INF;
	}
	dist[s] = 0;
	q.push(mmp(dist[s], s));
	int k,v;
	while(!q.empty()) {
		k = q.top().se;
		q.pop();
		if(vis[k]) continue;
		vis[k] = true;
		for(int i=First[k];~i;i=e[i].next) {
			v = e[i].v;
			if(dist[v] > dist[k] + e[i].w) {
				dist[v] = dist[k] + e[i].w;
				q.push(mmp(dist[v], v));
			}
		}
	}
	// for(int i=1;i<=N;++i) cout<<dist[i]<<" ";
	return dist[t];
}

int main(){
	init();
	scanf("%d%d", &N, &M);
	int a,b,c;
	for(int i=0;i<M;++i) {
		scanf("%d%d%d", &a, &b, &c);
		addEdge(a, b, c);
		addEdge(b, a, c);
	}
	int u,v;
	scanf("%d%d", &u, &v);
	printf("%d", Dij(u, v));
	return 0;
}