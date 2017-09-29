#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> g[25];

bool vis[25];

int N;

inline void addEdge(char u,char v){
	g[u].push_back(v);
	g[v].push_back(u);
}

int ans = 0x3f3f3f3;
char pre[1000],post[1000];

void dfs(int v,int maxw){
	if(v == N){
		ans = maxw;
		memcpy(post,pre,sizeof(pre));
	}else{
		
	}
}

int main(){

}