#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define OJ
const int MAXN = 32001;

int dp[MAXN];
int w[MAXN],v[MAXN],w1[MAXN],w2[MAXN],v1[MAXN],v2[MAXN];
int N,M;
int cur=0;
int main(){
	#ifdef OJ
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	#endif
	cin>>N>>M;
	int W,V,R;
	for(int i=1;i<=M;++i){
		cin>>W>>V>>R;
		if(R==0){
			w[i]=W;
			v[i]=V*W;
		}else{
			if(w1[R]==0 && v1[R]==0){
				w1[R]=W;
				v1[R]=V*W;
			}else{
				w2[R]=W;
				v2[R]=V*W;
			}
		}
	}
	for(int i=1;i<=M;++i){
		if(v[i]==0) continue;
		for(int j=N;j>0;--j){
			if(j>=w[i]){
				dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
			}
			if(j>=w[i]+w1[i]){
				dp[j]=max(dp[j-w[i]-w1[i]]+v[i]+v1[i],dp[j]);
			}
			if(j>=w[i]+w2[i]){
				dp[j]=max(dp[j-w[i]-w2[i]]+v[i]+v2[i],dp[j]);
			}
			if(j>=w[i]+w1[i]+w2[i]){
				dp[j]=max(dp[j-w[i]-w1[i]-w2[i]]+v[i]+v1[i]+v2[i],dp[j]);
			}
		}
	}
	cout<<dp[N];
	#ifdef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}