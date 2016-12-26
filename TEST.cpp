#include <iostream>
#include <cstdio>
#include <ctring>
using namespace std;
const int MAXN = 10001;
int main(){
  int m,n;
  cin>>m>>n;
  int u[MAXN];
  int v[MAXN];
  memset(u,0,sizeof(u));
  memset(v,0,sizeof(v));
  for(int i=1;i<=n;i++){
    con>>u[i]>>v[i];
  }
  int f[MAXN][MAXN];
  memset(f,0,sizeof(f));
  for(int i=1;i<=n;i++){
    for(int j=n;j>=i;j--){
      if(u[j]==i){
        f[i][j]=f[i-1][j]+1;
      }else{
        
      }
    }
  }
}
