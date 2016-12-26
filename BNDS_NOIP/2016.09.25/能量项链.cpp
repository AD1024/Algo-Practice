#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int a[210<<1];
int dp[210<<1][210<<1];
int N;
#define MAX(x,y) x>y?x:y
#define P(x,y,N) (x+y)%N;
//#define rep(i,f,t) for(int i=f;i<=t;++i)
//#define OJ
int main(){
#ifdef OJ
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
#endif
	cin>>N;
	for(int i=1;i<=N;++i) {
		cin>>a[i];
		a[i+N]=a[i];
	}
	for(int j=1;j<N;++j){
		for(int i=1;i+j<(N<<1);++i){
			for(int k=0;k<j;++k){
				dp[i][i+j]=MAX(dp[i][i+j],dp[i][i+k]+dp[i+1+k][i+j]+a[i]*a[i+k+1]*a[i+j+1]);
			}
		}
	}
	int ans=-1;
	for(int i=1;i<=N;++i){
		ans=MAX(ans,dp[i][i-1+N]);
	}
	cout<<ans;
#ifdef OJ
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
