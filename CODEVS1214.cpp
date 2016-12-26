#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 1000;

unsigned int idx[2010];

struct P{
	int u,v;
}list[110];

bool cmp(P a,P b){
	if(a.u==b.u){
		return a.v<b.v;
	}else{
		return a.u<b.u;
	}
}

void SWAP(int &a,int &b){
	a^=b^=a^=b;
}

int N;
int dp[110];
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		int s,e;cin>>s>>e;
		if(s>e){
			SWAP(s,e);
		}
		list[i].u=s;
		list[i].v=e;
		dp[i]=1;
	}
	sort(list,list+N,cmp);
	int ans=-1000;
	for(int i=0;i<N;++i){
		for(int j=0;j<i;++j){
			if(list[j].v<=list[i].u){
				dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
	}
	cout<<ans;
	return 0;
}
