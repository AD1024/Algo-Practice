#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 0x3f3f3f3f
int g[1001][1001];
int dp[1001][5];
inline void init(){
	memset(g,0,sizeof(g));
}
inline void add(int u,int v){
	g[u][v]=1;
}

inline int MIN(int x,int y){
	return x>y?y:x;
}

int main(){
	int N;
	cin>>N;
	int v;
	memset(g,0,sizeof(g));
	for(int i=2;i<=N;++i){
		cin>>v;
		add(v,i);
	}
	int m,n;
	for(int i=N;i>=1;--i){
		dp[i][0]=1;
		m=n=MAXN;
		for(int v=1;v<=N;++v){
			if(g[i][v]==1){
				dp[i][3]+=dp[v][2];
				dp[i][0]+=dp[v][4];
				dp[i][4]+=dp[v][3];
				m=MIN(m,dp[v][0]-dp[v][3]);
				n=MIN(n,dp[v][1]-dp[v][2]);
			}
		}
		dp[i][1]=dp[i][4]+m;
		dp[i][2]=MIN(MIN(dp[i][1],dp[i][0]),dp[i][3]+n);
		dp[i][3]=MIN(dp[i][3],dp[i][2]);
		dp[i][4]=MIN(dp[i][3],dp[i][4]);
	}
	cout<<dp[1][2];
	return 0;
}