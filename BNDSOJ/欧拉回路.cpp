#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int g[30][30];
bool used[30][30];
bool vis[30];
int degree[30];
int N,K;
stack<int> ans;
int Stack[40];
int cur=0;
int getEurler(int u){
	for(int i=1;i<=N;++i){
		if(g[u][i]){
			g[u][i]--;
			g[i][u]--;
			degree[u]--;
			degree[i]--;
			getEurler(i);
		}
	}
	ans.push(u);
}

int main(){
	memset(g,0,sizeof(g));
	cin>>N>>K;
	int u,v;
	for(int i=0;i<K;++i){
		scanf("%d%d",&u,&v);
		g[u][v]++;
		g[v][u]++;
		degree[u]++;degree[v]++;
	}
	for(int i=1;i<=N;++i){	
		if(degree[i]&1){
			puts("no oula circle");
			return 0;
		}
	}
	getEurler(1);
	while(!ans.empty()){
		printf("%d ",ans.top());ans.pop();
	}
	return 0;
}
