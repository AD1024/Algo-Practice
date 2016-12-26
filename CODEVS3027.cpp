#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001],N;

struct Node{
	int l,r,w;
}list[1001];


bool cmp(Node a,Node b){
	return a.l<b.l;
}

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		Node n;
		cin>>n.l>>n.r>>n.w;
		list[i]=n;
	}
	sort(list+1,list+1+N,cmp);
	for(int i=1;i<=N;++i){
		dp[i]=list[i].w;
		for(int j=1;j<i;++j){
			if(list[i].l>=list[j].r && dp[i]<dp[j]+list[i].w){
				dp[i]=list[i].w+dp[j];
			}
		}
	}
	int ans=-1000;
	for(int i=1;i<=N;++i){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}