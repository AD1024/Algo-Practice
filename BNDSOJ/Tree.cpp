#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 10010
vector<int> g[MAXN];
queue<int> q;
inline void addEdge(int u,int v){
	g[u].push_back(v);
}
int N,M;
int ans[MAXN];
int main(){
	cin>>N>>M;
	for(int i=1;i<=M;++i){
		int u,v;cin>>u>>v;
		addEdge(v,u);
	}
	for(int i=0;i<=N;++i) ans[i]=-1;
	for(int i=N;i>=1;--i){
		if(ans[i]==-1){
			ans[i]=i;
			q.push(i);
			while(q.size()){
				int u=q.front();q.pop();
				for(int j=0;j<g[u].size();++j){
					int v=g[u][j];
					if(ans[v]==-1){
						ans[v]=i;
						q.push(v);
					}
				}
			}
		}
	}
	for(int i=1;i<=N;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}