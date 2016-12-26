#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;

int M,N;
bool f=false;
char g[1501][1501];
int vis[1501][1501][2];

const int D[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

bool dfs(int x,int y){
	int xx=(x%M+M)%M;
	int yy=(y%N+N)%N;
	if(g[xx][yy]=='#') return false;
	if(vis[xx][yy][0]!=0x3f3f3f){
		return vis[xx][yy][1]!=y || vis[xx][yy][0]!=x;
	}
	vis[xx][yy][0]=x;
	vis[xx][yy][1]=y;
	for(int i=0;i<4;++i){
		if(dfs(x+D[i][0],y+D[i][1])) return true;
	}
	return false;
}

int main(){
    while(cin>>M>>N){
    	int x1,y1;
    	f=false;
    	for(int i=0;i<M;i++){
        	for(int j=0;j<N;j++){
            	cin>>g[i][j];
            	if(g[i][j]=='S'){
            		x1=i;
            		y1=j;
            	}
            	vis[i][j][0]=0x3f3f3f;
        	}
    	}
    	if(dfs(x1,y1))
    		cout<<"Yes\n";
    	else cout<<"No\n";
	}
    return 0;
}