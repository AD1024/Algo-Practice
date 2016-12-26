#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[50][50];
int n;
int vis[50][50];
void dfs_map(int i,int j){
  if(i>n+1 || i<0 || j>n+1 || j<0 || map[i][j]==1 || vis[i][j]==4){
    return;
  }
  map[i][j]=0;
  vis[i][j]++;
  dfs_map(i+1,j);
  dfs_map(i-1,j);
  dfs_map(i,j+1);
  dfs_map(i,j-1);
}

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>map[i][j];
      if(map[i][j]==0) map[i][j]=2;
      vis[i][j]=0;
    }
  }
  dfs_map(0, 0);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout<<map[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
