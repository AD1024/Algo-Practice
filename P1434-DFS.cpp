#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int map[110][110];
int R,C;
int cnter[110][110];
bool vis[110][110];
void dfs(int x,int y){
	vis[x][y]=true;
	if(x-1>0 && map[x-1][y]<map[x][y]){
		if(!vis[x-1][y])
			dfs(x-1,y);
		cnter[x][y]=max(cnter[x][y],cnter[x-1][y]);
	}
	if(x+1<=R && map[x+1][y]<map[x][y]){
		if(!vis[x+1][y])
			dfs(x+1,y);
		cnter[x][y]=max(cnter[x][y],cnter[x+1][y]);
	}
	if(y-1>=1 && map[x][y-1]<map[x][y]){
		if(!vis[x][y-1])
			dfs(x,y-1);
		cnter[x][y]=max(cnter[x][y],cnter[x][y-1]);
	}
	if(y+1<=C && map[x][y+1]<map[x][y]){
		if(!vis[x][y+1])
			dfs(x,y+1);
		cnter[x][y]=max(cnter[x][y],cnter[x][y+1]);
	}
	cnter[x][y]+=1;
}

int main(){
	cin>>R>>C;
	int cur=1;
	for(int i=1;i<=R;++i){
		for(int j=1;j<=C;++j){
			cin>>map[i][j];
		}
	}
	int ans=-100;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;++j){
			if(!vis[i][j]){
				dfs(i,j);
			}
			ans=max(ans,cnter[i][j]);
		}
	}
	cout<<ans;
	return 0;
}