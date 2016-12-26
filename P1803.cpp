#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000001;

int st[MAXN];
int maxIn=-1000;
int dp[MAXN];
int ans=-10000;
inline int max1(int a,int b){
	return a>b?a:b;
}

inline void init(){
	memset(st,-1,sizeof(st));
	memset(dp,0,sizeof(dp));
}

inline void in(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int s,e;
		scanf("%d%d",&s,&e);
		st[e]=max1(st[e],s);
		maxIn=max1(e,maxIn);
	}
}

inline void solve(){
	for(int i=0;i<=maxIn;++i){
		if(st[i]!=-1) dp[i]=max1(dp[st[i]]+1,dp[i-1]);
		else dp[i]=dp[i-1];
		ans=max1(dp[i],ans);
	}
	cout<<ans;
}

int main(){
	init();
	in();
	solve();
	exit(0);
}