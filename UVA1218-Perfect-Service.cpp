#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 10001;
int N;
vector<int> g[MAXN];
int dp[MAXN][MAXN];
bool vis[MAXN];
/*
State:
F[u][0]->u is server->u's child can be ether server or pc
F[u][1]->u is not a server and there is a server among u's children->u's father isn't a server
F[u][2]->u and u's children aren't server but u's father is a server.

According to the description:
F[u][0] can trans-state from min(sigma(F[v][2] + F[v][0]))+1
F[u][1] can trans-state from min(sigma(F[v][1])-F[v][1]+F[v][0])--->Explanation:Attempt each state of u's child(F[v][1]->certain child is not a server  F[v][0]->certain child is a server)
sigma(F[v][1]) can be represented by F[u][2]

F[u][2] can tans-state from sigma(F[v][1])
*/

inline void init(){
	for(int i=0;i<=N;i++){
		g[i].clear();
	}
	for(int i=0;i<=N;++i){
		vis[i]=false;
	}
}

void dps(int pos){
	vis[pos]=true;
	dp[pos][0]=1;dp[pos][1]=MAXN;dp[pos][2]=0;
	queue<int> q;
	for(int i=0;i<g[pos].size();i++){
		if(!vis[g[pos][i]]){
			dps(g[pos][i]);
			q.push(g[pos][i]);
			dp[pos][0]+=min(dp[g[pos][i]][0],dp[g[pos][i]][2]);
			dp[pos][2]+=dp[g[pos][i]][1];
		}
	}
	while(!q.empty()){
		dp[pos][1]=min(dp[pos][1],dp[pos][2]-dp[q.front()][1]+dp[q.front()][0]);
		q.pop();
	}
	return;
}

int main(){
	while(~scanf("%d",&N)&& N!=-1){
		if(!N) continue;
		int tu,tv;
		init();
		for(int i=1;i<N;i++){
			cin>>tu>>tv;
			g[tu].push_back(tv);
			g[tv].push_back(tu);
		}
		dps(1);
		cout<<min(dp[1][0],dp[1][1])<<endl;
	}
	return 0;
}