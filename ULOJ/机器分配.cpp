#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int N,M;

int dp[200][200];

int v[30][30];

int ans[30];

int main(){
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			cin>>v[i][j];
		}
	}
	dp[1][1] = v[1][1];
	memset(ans,0x3f3f3f,sizeof(ans));
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			for(int k=0;k<=j;++k){
				if(dp[i][j] < dp[i-1][j-k] + v[i][k]){
					dp[i][j] = dp[i-1][j-k] + v[i][k];
				}
			}
		}
	}
	cout<<dp[N][M]<<endl;
	for(int i=1;i<=N;++i){
		cout<<i<<" "<<ans[i]<<"\n";
	}
	return 0;
}