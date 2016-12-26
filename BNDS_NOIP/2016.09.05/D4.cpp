#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//#define DEBUG
int dp[1001];
int w[33],v[33],w1[33],v1[33];
int N,TOT;

int main(){
	#ifndef DEBUG
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	#endif
	cin>>N>>TOT;
	for(int i=1;i<=N;++i){
		cin>>w[i]>>v[i];
		cin>>w1[i]>>v1[i];
	}
	for(int i=1;i<=N;++i){
		for(int j=TOT;j>=w[i] || j>=w1[i];--j){
			if(j>=w[i]){
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
			if(j>=w1[i]){
				dp[j]=max(dp[j],dp[j-w1[i]]+v1[i]);
			}
		}
	}
	cout<<dp[TOT];
	#ifndef DEBUG
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}