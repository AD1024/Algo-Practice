#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define INF 0xfffffffffff
const int N = 5;
#define ll long long
bool vis[5][5][50];
ll g[N][N];
ll dp[N][N][50];
ll tot[N][N];
int n;
ll dfs(int l,int r,int idx){
	if(vis[l][r][idx]) return dp[l][r][idx];
	vis[l][r][idx]=true;
	int x=6-(l+r);
	if(idx==1){
		dp[l][r][idx]=tot[l][r];
		return dp[l][r][idx];
	}
	dp[l][r][idx]=dfs(l,x,idx-1)+dfs(x,r,idx-1)+g[l][r];
	ll tmp=dfs(l,r,idx-1)*2+dfs(r,l,idx-1)+g[l][x]+g[x][r];
	dp[l][r][idx]=min(dp[l][r][idx],tmp);
	return dp[l][r][idx];
}

inline void init(){
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			cin>>g[i][j];
			tot[i][j]=g[i][j];
		}
	}
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			for(int k=1;k<=3;++k){
				if(i==j) break;
				tot[i][j]=min(tot[i][j],tot[i][k]+tot[k][j]);
			}
		}
	}
	cin>>n;
}
int main(){
	init();
	cout<<dfs(1,3,n);
	return 0;
}