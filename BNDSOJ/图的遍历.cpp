#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 1010000

vector<int> g[MAXN];

bool vis[MAXN];

vector<int> ansa;

int N,M;

inline void addEdge(int u,int v) {
	g[u].push_back(v);
}

inline void work() {
	for(int i=1;i<=N;++i) {
		sort(g[i].begin(), g[i].end());
	}
}

inline void out(vector<int> v) {
	int sz = v.size();
	for(int i=0;i<sz-1;++i){
		printf("%d-", v[i]);
	}
	printf("%d", v[sz-1]);
	if(sz < N) {
		for(int i=sz+1;i<=N;++i){
			printf("-%d", i);
		}
	}
}

inline void bfs() {
	static queue<int> q;
	memset(vis, false, sizeof(vis));
	q.push(1);
	vis[1] = true;
	static vector<int> ansb;
	ansb.push_back(1);
	int k,v;
	while(!q.empty()) {
		k = q.front();q.pop();
		for(int i=0;i<g[k].size();++i){
			v = g[k][i];
			if(!vis[v]) {
				vis[v] = true;
				q.push(v);
				ansb.push_back(v);
			}
		}
	}
	out(ansb);
}

void dfs(int u) {
	ansa.push_back(u);
	for(int i=0;i<g[u].size();++i) {
		int v = g[u][i];
		if(!vis[v]) {
			vis[v] = true;
			dfs(v);
		}
	}
}

int main(){
	scanf("%d%d", &N, &M);int a,b;
	for(int i=0;i<M;++i){
		scanf("%d%d", &a, &b);
		addEdge(a,b);
		addEdge(b,a);
	}
	work();
	vis[1] = true;
	dfs(1);
	out(ansa);
	puts("");
	bfs();
	return 0;
}