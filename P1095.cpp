#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int dp[300000+10];

int main(){
	int M,S,T;
	cin>>M>>S>>T;
	for(int i=1;i<=T;++i){
		if(M>=10){
			M-=10;
			dp[i]=dp[i-1]+60;
		}else{
			dp[i]=dp[i-1];
			M+=4;
		}
	}
	for(int i=1;i<=T;++i){
		if(dp[i]<dp[i-1]+17){
			dp[i]=dp[i-1]+17;
		}
		if(dp[i]>=S){
			cout<<"Yes\n";
			cout<<i;
			return 0;
		}
	}
	cout<<"No\n"<<dp[T];
	return 0;
}