#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 210;
int g[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
	int m,n;
	cin>>m>>n;
	memset(g,0,sizeof(g));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	for(int j=1;j<=n;j++){
		dp[1][j]=g[1][j];
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]))+g[i][j];
		}
	}
	int ans=-100000;
	for(int i=n/2;i<=n/2+2;i++){
		//cout<<dp[m][i]<<" ";
		ans=max(ans,dp[m][i]);
	}
	cout<<ans;
	return 0;
}