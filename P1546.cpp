#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;
const int INF = 0x3f3f3f3f;
int g[MAXN][MAXN];
int n;
int prim(){
  int low[MAXN];
  int min;
  bool vis[MAXN];
  int res=0;
  memset(vis,false,sizeof(vis));
  int pos=1;
  vis[1]=true;
  low[pos]=INF;
  for(int i=1;i<=n;i++){
    if(i!=pos){
      low[i]=g[pos][i];
    }
  }
  for(int i=1;i<n;i++){
    min=INF;
    for(int j=1;j<=n;j++){
      if(!vis[j]&&min>low[j]){
        min=low[j];
        pos=j;
      }
    }
    res+=min;
    vis[pos]=true;
    for(int j=1;j<=n;j++){
      if(!vis[j]&&low[j]>g[pos][j]){
        low[j]=g[pos][j];
      }
    }
  }
  return res;
}

int main(){
	scanf("%d",&n);
    memset(g,INF,sizeof(g));
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        int v;
        cin>>v;
        g[i][j]=v;
      }
    }
    int ans=prim();
    cout<<ans<<endl;
  return 0;
}
