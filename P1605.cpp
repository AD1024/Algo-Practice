#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000;
int g[MAXN][MAXN];
int cnt=0;
int ux,uy;
int vx,vy;
int m,n;
bool vis[MAXN][MAXN];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y){
  if(x>m || y>n || x<1 || y<1 || vis[x][y] || g[x][y]==-1) return;
    if(x==vx && y==vy){
      cnt++;
      return;
    }
    for(int i=0;i<4;i++){
      vis[x][y]=true;
      dfs(x+dir[i][0],y+dir[i][1]);
      vis[x][y]=false;
    }
}

int main(){
  int T;
  memset(g,0,sizeof(g));
  cin>>m>>n>>T;
  cin>>ux>>uy>>vx>>vy;
  for(int i=0;i<T;i++){
    int bx,by;
    cin>>bx>>by;
    g[bx][by]=-1;
    vis[bx][by]=true;
  }
  dfs(ux,uy);
  cout<<cnt;
  return 0;
}
