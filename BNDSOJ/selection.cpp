#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int a[40];
inline bool ok(int x){
	if(x==2) return true;
	if(x==1) return false;
	for(int i=2;i<=sqrt(x);++i){
		if(!(x%i)) return false;
	}
	return true;
}
int N,K;
int ans=0;
bool vis[40];

void dfs(int idx,int sum,int from){
	if(idx==K){
		if(ok(sum)){
			ans++;
		}
	}else{
		for(int i=from;i<=N;++i){
			if(!vis[i]){
				vis[i]=true;
				dfs(idx+1,a[i]+sum,i+1);
				vis[i]=false;
			}
		}
	}
}

int main(){
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}