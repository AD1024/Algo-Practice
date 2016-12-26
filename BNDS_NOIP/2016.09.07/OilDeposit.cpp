#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,-1,1,1,-1};

char g[110][110];
bool vis[110][110];
int N,M;
int ans=0;
void dfs(int x,int y){
    if(vis[x][y]) return;
    if(x>N || x<1 || y<1 || y>M) return;
    vis[x][y]=true;
    int xx,yy;
    for(int i=0;i<8;++i){
        xx=x+dx[i];
        yy=y+dy[i];
        if(g[xx][yy]=='@' && !vis[xx][yy]){
            dfs(xx,yy);
        }
    }
}

int main(){
    while(cin>>N>>M){
    	ans=0;
        if(N==0 && M==0) break;
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                cin>>g[i][j];
            }
        }
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                if(!vis[i][j] && g[i][j]=='@'){
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}