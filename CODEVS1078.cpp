#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 110;
const int INF = 0x3f3f3f3f;
int g[MAXN][MAXN];
bool vis[MAXN];
int n;
void init(){
  memset(g,INF,sizeof(g));
  memset(vis,false,sizeof(vis));
}

int prim(){
  int res=0;
  int min;
  int pos=1;
  vis[pos]=true;
  int dis[MAXN];
  dis[pos]=INF;
  memset(dis,INF,sizeof(dis));
  for(int i=1;i<=n;i++){
    if(pos!=i){
      dis[i]=g[pos][i];
    }
  }
  for(int i=1;i<n;i++){
    min=INF;
    for(int j=1;j<=n;j++){
      if(!vis[j]&&min>dis[j]){
        min=dis[j];
        pos=j;
      }
    }
    vis[pos]=true;
    res+=min;
    for(int j=1;j<=n;j++){
      if(!vis[j]&&dis[j]>g[pos][j]){
        dis[j]=g[pos][j];
      }
    }
  }
  return res;
}

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>g[i][j];
    }
  }
  cout<<prim();
  return 0;
}
