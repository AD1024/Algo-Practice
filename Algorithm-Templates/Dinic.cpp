#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

struct Edge{
	int u,v,w;
	int Next;
};

int First[10100];
Edge e[10100];

int EID = 1;

int dep[10100];

int S,T;

inline void addEdge(int u,int v,int w){
	e[EID].Next = First[u];
	e[EID].u = u;
	e[EID].v = v;
	e[EID].w = w;
	First[u] = EID++;
}

inline bool BFS(){
	queue<int> q;
	memset(dep,-1,sizeof(dep));
	q.push(S);
	int k;
	while(!q.empty()){
		k = q.front();q.pop();
		for(int i = First[k];i;i=e[i].Next){
			if(dep[e[i].v]<0 && e[i].w > 0){
				q.push(e[i].v);
				dep[e[i]] = dep[k] + 1;
			}
		}
	}
	return dep[T] > 0;
}

int DFS(int v,int INF){
	if(v == T) return INF;
	else{
		int ret = 0;
		for(int i=First[v];i;i=e[i].Next){
			int cap = e[i].w;
			int to = w[i].v;int a;
			if(dep[to] == dep[v] + 1 && cap > 0 && (a = DFS(v,min(INF,cap)))){
				e[i].w -= a;
				e[i^1].w += a;
				return a;
			}
		}
		dep[v] = -1;
		return 0;
	}
}

inline int dinic(){
	int ans = 0;
	while(BFS()){
		ans += dfs(S,0x3f3f3f3f);
	}
	cout<<ans;
}

int main(){

}