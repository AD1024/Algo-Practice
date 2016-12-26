#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int g[44][44];
bool vis[44][44];
int N;int ans=0x3f3ff3f;
void DFS(int x,int y,int dep){
	if(x<1 || x>N || y<1 || y>N) return;
	if(g[x][y]==1) return;
	if(x==1 && y==1){
		ans=min(ans,dep);
	}else{
		int px,py;
		for(int i=0;i<4;++i){
			px=x+dx[i];
			py=y+dy[i];
			if(!vis[px][py]){
				vis[px][py]=true;
				DFS(px,py,dep+1);
				vis[px][py]=true;
			}
		}
	}
}

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>g[i][j];
		}
	}
	DFS(N,N,1);
	cout<<ans;
	return 0;
}