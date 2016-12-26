#include <iostream>
#include <cstring>
using namespace std;

int dp[1010];
int w[110];
int v[100];

int main(){
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=M;++i){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=M;++i){
		for(int j=N;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[N];
	return 0;
}