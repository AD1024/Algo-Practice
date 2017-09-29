#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 500
#define INF 0x3f3f3f3f

vector<int> g[MAXN];

int dist[MAXN];
bool vis[MAXN];
int N;

inline bool ok(int a,int b) {
	return a >= 1 && a <= N && b >= 1 && b <= N;
}

inline void addEdge(int u,int v) {
	if(ok(u,v)) {
		g[u].push_back(v);
	}
}

inline int spfa(int s,int t){
	memset(dist, INF, sizeof(dist));
	queue<int> q;
	vis[s] = true;
	q.push(s);
	dist[s] = 0;
	int k,v;
	while(!q.empty()) {
		k = q.front();q.pop();
		vis[k] = false;
		for(int i=0;i<g[k].size();++i) {
			v = g[k][i];
			if(dist[v] > dist[k] + 1) {
				dist[v] = dist[k] + 1;
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dist[t] == INF?-1:dist[t];
}

int main(){
	int s,t;
	scanf("%d%d%d", &N, &s, &t);
	int a;
	for(int i=1;i<=N;++i){
		scanf("%d", &a);
		addEdge(i, i+a);
		addEdge(i, i-a);
	}
	printf("%d\n", spfa(s,t));
	return 0;
}