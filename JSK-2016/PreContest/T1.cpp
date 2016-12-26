#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 0xffffff;

int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int m,n;
bool vis[200][200];
int g[200][200];
int ans=0;
int minm=MAXN;
int zcnt=0;

inline void init(){
    memset(vis,false,sizeof(vis));
    memset(g,0,sizeof(g));
}

void dfs(int x,int y){
    if(x>n || x<1 || y>m || y<1) return;
    if(vis[x][y]) return;
    vis[x][y]=true;
    if(!(g[x-1][y] || g[x+1][y] || g[x][y-1] || g[x][y+1] || g[x][y])){
        ans++;
        g[x][y]=g[x-1][y] = g[x+1][y] = g[x][y-1] = g[x][y+1]=1;
    }
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]==0) zcnt+=1;
        }
    }
    if(zcnt%5!=0){
        cout<<"no solution";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dfs(i,j);
        }
    }
    if(ans==0){
        cout<<"no solution";
    }else{
        cout<<ans;
    }
    return 0;
}
