#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int g[10][10];
bool vis[10][10];
int N,M;

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

inline bool valid(int x,int y){
    if(x < 1 || x > N || y < 1 || y > M) return false;
    return true;
}

void dfs(int x,int y,int w){
    g[x][y]=0;
    vis[x][y] = true;
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx,ny) && !vis[nx][ny] && g[nx][ny] == w){
            dfs(nx,ny,w);
        }
    }
}

int main(){
    while(scanf("%d%d", &N,&M)){
        memset(vis,false,sizeof(vis));
        int ans = 0;
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                scanf("%d", &g[i][j]);
            }
        }
        
        printf("%d\n", ans);
    }
    return 0;
}