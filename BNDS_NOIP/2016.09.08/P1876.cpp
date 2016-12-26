#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int g[5][5];
int ans=10;
bool vis[5][5];

inline bool ok(){
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			if(!g[i][j]) return false;
		}
	}
	return true;
}

void dfs(int idx){
	if(idx==10) return;
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			if(!vis[i][j]){
				vis[i][j]=true;
				g[i][j]=!g[i][j];
				g[i-1][j]=!g[i-1][j];
				g[i+1][j]=!g[i+1][j];
				g[i][j+1]=!g[i][j+1];
				g[i][j-1]=!g[i][j-1];
				if(ok()){
					ans=min(ans,idx);
				}
				dfs(idx+1);
				vis[i][j]=false;
				g[i][j]=!g[i][j];
				g[i-1][j]=!g[i-1][j];
				g[i+1][j]=!g[i+1][j];
				g[i][j+1]=!g[i][j+1];
				g[i][j-1]=!g[i][j-1];
			}
		}
	}
}

int main(){
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			cin>>g[i][j];
		}
	}
	if(ok()){cout<<0;return 0;}
	dfs(1);
	cout<<ans;
	return 0;
}