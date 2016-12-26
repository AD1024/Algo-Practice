#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int dp[1010][1010];

int M,N;

int c[1010],d[1010];
int sum[1010];
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>d[i];
	}
	for(int i=0;i<M;++i){
		cin>>c[i];
	}
	for(int i=0;i<N;++i){
		for(int j=i;j<M;++j){
			dp[i+1][j]=dp[i][j-1]+d[i]*c[j];
			if(j>i) dp[i+1][j]=min(dp[i+1][j],dp[i+1][j-1]);
		}
	}
	cout<<dp[N][M-1];
	return 0;
}