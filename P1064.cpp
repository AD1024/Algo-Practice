#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w[1001],v[1001],r[1001];
int f1w[70],f1v[70],f2w[70],f2v[70];
int N,m;
int dp[32000+10];

int main(){
	cin>>N>>m;
	for(int i=1;i<=m;++i){
		int ww,vv,rr;
		cin>>vv>>ww>>rr;
		if(rr==0){
			w[i]=vv*ww;
			v[i]=vv;
		}else if(f1w[rr]==0){
			f1v[rr]=vv;
			f1w[rr]=vv*ww;
		}else{
			f2v[rr]=vv;
			f2w[rr]=ww*vv;
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;++i){
		if(!v[i]) continue;
		for(int j=N;j>0;--j){
			if(j-v[i]>=0){

				dp[j]=max(dp[j],dp[j-v[i]]+w[i]);

			}
			if(j-v[i]-f1v[i]>=0){

				dp[j]=max(dp[j],dp[j-v[i]-f1v[i]]+w[i]+f1w[i]);

			}
			if(j-v[i]-f2v[i]>=0){

				dp[j]=max(dp[j],dp[j-v[i]-f2v[i]]+w[i]+f2w[i]);

			}
			if(j-v[i]-f1v[i]-f2v[i]>=0){

				dp[j]=max(dp[j],dp[j-v[i]-f1v[i]-f2v[i]]+w[i]+f1w[i]+f2w[i]);

			}
		}
	}
	cout<<dp[N];
	return 0;
}