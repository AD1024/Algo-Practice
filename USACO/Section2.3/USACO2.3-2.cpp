/*
ID: ccodera1
LANG: C++
TASK: nocows
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int dp[300][300];
int a[300][300];

#define MOD 9901

int main(){
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	int N,K;cin>>N>>K;
	dp[1][1]=1;
	for(int i=2;i<=K;++i){
		for(int j=1;j<=N;j+=2){
			for(int k=1;k<=j-k-1;k+=2){
				int t = 2;
				if(k == j-1-k) t=1;
				dp[i][j] += t*(
					(a[i-2][k]*dp[i-1][j-k-1]) % MOD 
					+(dp[i-1][k]*a[i-2][j-k-1]) % MOD
					+ (dp[i-1][k]*dp[i-1][j-k-1]) % MOD);
				dp[i][j] %= MOD;
			}
		}
		for(int k=0;k<=N;++k){
			a[i-1][k]+=a[i-2][k]+dp[i-1][k];
			a[i-1][k] %= MOD;
		}
	}
	cout<<dp[K][N]<<endl;
	return 0;
}