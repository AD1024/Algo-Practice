#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int dp[1001][1001];

int main(){
	int V,M;
	cin>>V>>M;
	int w[1001],v[1001],m[1001];
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>v[i]>>m[i]>>w[i];
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=N;i++){
		for(int j=V;j>=v[i];j--){
			for(int k=M;k>=m[i];k--){
				dp[j][k]=max(dp[j][k],dp[j-v[i]][k-m[i]]+w[i]);
			}
		}
	}
	cout<<dp[V][M];
	return 0;
}