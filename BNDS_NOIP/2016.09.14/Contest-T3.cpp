#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int d[60001];
int a[60001];
int dp[60001];
int b[60001];
int N;

int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>d[i]>>b[i]>>a[i];
	}
	for(int i=1;i<=N;++i){
		dp[i]=max(dp[i],dp[i-d[i-1]]+b[i]);
		for(int j=0;j<=i;++j){
			dp[i]=max(dp[i],dp[j]+b[i]-abs(i-j)*a[j]);
		}
	}
	cout<<dp[N];
	return 0;
}