#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool g[210][210];
int n,m;
void init(){
  cin>>n>>m;
  int ctr=m/2+1;
  int cntr = 3,t;
  for(int i=n,cur=1;i>=1;i--,cur++){
      int u = ctr-cur;
      if(cntr==m){
          t=i;
          break;
      }
      for(int j=0;j<cntr;j++){
          g[i][u+j]=true;
      }
      cntr+=2;
  }
  while(t>=1){
      for(int j=1;j<=m;j++){
          g[t][j]=true;
      }
      t--;
  }
}

int main(){
    init();
    int map[210][210];
    int a[210][210];
    memset(a,0,sizeof(a));
    memset(map,0,sizeof(map));
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin>>map[i][j];
      }
    }
    for(int i=n;i>=1;i--){
      for(int j=1;j<=m;j++){
        if(!g[i][j]) continue;
        a[i][j]=max(a[i][j],a[i+1][j]);
        if(g[i+1][j-1]) a[i][j]=max(a[i][j],a[i+1][j-1]);
        if(g[i+1][j+1]) a[i][j]=max(a[i][j],a[i+1][j+1]);
        a[i][j]+=map[i][j];
      }
    }
    int maxn = -1000;
    for(int i=1;i<=m;i++){
      maxn = max(maxn,a[1][i]);
    }
    cout<<maxn;
    return 0;
}
