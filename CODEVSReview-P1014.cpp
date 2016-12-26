#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200010;

int dp[MAXN];

int a[MAXN];

int main(){
	int n;int m;
	cin>>n>>m;;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=a[i];j--){
			dp[j]=max(dp[j-a[i]]+a[i],dp[j]);
		}
	}
	cout<<n-dp[n];
	return 0;
}