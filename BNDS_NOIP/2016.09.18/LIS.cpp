#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int dp[10001];
int a[10001];
int N;
int main(){
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
		dp[i]=1;
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<i;++j){
			if(a[j]<=a[i] && dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}
	int ans=-100;
	for(int i=1;i<=N;++i){
		if(ans<dp[i]){
			ans=dp[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}