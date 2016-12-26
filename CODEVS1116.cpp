#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int g[10][10];
int n;
int ans=0;
int color[10];
void dfs(int pos,int col){
  if(pos==n+1){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(g[i][j] && color[i]==color[j]){
          return;
        }
      }
    }
    ans++;
    return;
  }
  color[pos]=col;
  for(int i=1;i<=4;i++){
    dfs(pos+1,i);
  }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        scanf("%d",&g[i][j]);
      }
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
