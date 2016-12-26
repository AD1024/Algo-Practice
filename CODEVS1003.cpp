#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;
const int INF = 0x3f3f3f3f;
int g[MAXN][MAXN];
int low[MAXN];
bool vis[MAXN];
int n;
int path[MAXN];
int cnt=0;
int u[MAXN];
int res=0;
void init(){
  memset(g,0,sizeof(g));
  memset(path,-1,sizeof(path));
  memset(vis,false,sizeof(vis));
  memset(low,0,sizeof(low));
}

void prim(){
  int pos=1;
  vis[pos]=true;
  low[pos]=INF;
  for(int i=1;i<=n;i++){
    if(i!=pos){
      low[i]=g[pos][i];
    }
  }
  int min=INF;
  for(int i=1;i<n;i++){
    min=INF;
    for(int j=1;j<=n;j++){
      if(!vis[j]&&low[j]<min){
        min = low[j];
        pos=j;
        path[pos]=j;
        u[cnt++]=pos;
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
}

void show(){
  cout<<cnt<<endl;
  for(int i=1;i<=cnt;i++){
      cout<<u[i]<<" "<<path[u[i]];
  }
  cout<<endl<<res;
  return;
}

int main(){
  cin>>n;
  init();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>g[i][j];
    }
  }
  show();
  return 0;
}
