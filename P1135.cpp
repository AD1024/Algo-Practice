#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN = 400;
const int INF = 0xffffff;
int map[MAXN][MAXN];
int main(){
  int n,begin,end;
  cin>>n>>begin>>end;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j)
        map[i][j]=0;
      else{
        map[i][j]=INF;
      }
    }
  }
  for(int i=1;i<=n;i++){
    int t;
    cin>>t;
    if(i+t<=n){
      map[i][t+i]=1;
    }
    if(i-t>=1){
      map[i][i-t]=1;
    }
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(map[i][j]>map[i][k]+map[k][j]){
          map[i][j]=map[i][k]+map[k][j];
        }
      }
    }
  }
  printf("%d\n",map[begin][end]<INF?map[begin][end]:-1);
  return 0;
}
