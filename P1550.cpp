#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 310;
const int INF = 0x3f3f3f3f;
int g[MAXN][MAXN];
int n;
int prim(){
  int res;
  bool vis[MAXN];
  int low[MAXN];
  memset(vis,false,sizeof(vis));
  memset(low,0,sizeof(low));
  int min=INF;
  int pos=1;
  vis[pos]=true;
  low[pos]=INF;
  for(int i=1;i<=n;i++){
    if(i!=pos){
      low[i]=g[pos][i];
    }
  }
  for(int i=1;i<n;i++){
    min = INF;
    for(int j=1;j<=n;j++){
      if(!vis[j] && low[j]<min){
        min = low[j];
        pos=j;
      }
    }
    vis[pos]=true;
    res+=min;
    for(int j=1;j<=n;j++){
      if(!vis[j] && low[j]>g[pos][j]){
        low[j]=g[pos][j];
      }
    }
  }
  return res;
}

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      g[i][j]=INF;
    }
  }
  int wi;
  for(int i=1;i<=n;i++){
    cin>>wi;
    g[n+1][i]=g[i][n+1]=wi;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int w;
      cin>>w;
      if(i!=j){
        g[i][j]=w;
      }
    }
  }
  n+=1;
  cout<<prim();
  return 0;
}
