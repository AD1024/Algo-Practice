#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define OJ

int dp[10001];
int w[10001],v[10001];
int M,N;
int main(){
	#ifdef OJ
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=N;++i){
		for(int j=M;j>=w[i];--j){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[M];
	#ifdef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}