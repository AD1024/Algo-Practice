#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int h[10001];
int dp[10001][2];
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int N;
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>h[i];
	}
	dp[1][0]=dp[1][1]=1;
	for(int i=1;i<=N;++i){
		for(int j=1;j<i;++j){
			if(h[j]>h[i] && dp[j][0]+1>dp[i][1]){
				dp[i][1]=dp[j][0]+1;
			}
			if(h[j]<h[i] && dp[j][1]+1>dp[i][0]){
				dp[i][0]=dp[j][1]+1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=N;++i){
		ans=max(ans,max(dp[i][0],dp[i][1]));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}