/*
ID: ccodera1
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[400];
int dp[210][210];
int M,C,S;
inline void filein(){
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
}

int main(){
	filein();
	cin>>M>>S>>C;
	for(int i=1;i<=C;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+C);
	memset(dp,0x3f3f3f,sizeof(dp));
	dp[0][0]=0;
	int ans = 0x33f3f3f;
	for(int i=1;i<=M;++i){
		for(int j=1;j<=C;++j){
			dp[i][j]=min(dp[i-1][j-1]+1,dp[i][j-1]+a[j]-a[j-1]);
			if(j==C){
				ans=min(ans,dp[i][j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}