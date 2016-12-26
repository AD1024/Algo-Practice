#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAXN 510

bool g[MAXN][MAXN];

bool vis[MAXN];
int idx[MAXN];

int M,N,R;

bool Find(int x){
	for(int i=1;i<=M;++i){
		if(g[x][i] && !vis[i]){
			vis[i]=true;
			if(idx[i]==0 || Find(idx[i])){
				idx[i]=x;
				return true;
			}
		}
	}
	return false;
}
int tt[1001];
int main(){
	cin>>N>>M>>R;
	int ans=0;
	for(int i=1;i<=R;++i){
		int u,v;cin>>u>>v;
		g[u][v]=1;
	}
	for(int i=1;i<=N;++i){
		memset(vis,false,sizeof(vis));
		if(Find(i)) ++ans;
	}
	cout<<ans<<endl;
	for(int i=1;i<=M;++i){
		tt[idx[i]]=i;
	}
	for(int i=1;i<=N;++i){
		cout<<tt[i]<<" ";
	}
	return 0;
}