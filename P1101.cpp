#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 101;
char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n;
int dir[8][2]={{0,1},{0,-1},{-1,0},{1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
char s[]={'y','i','z','h','o','n','g'};
int cnt=0;
void dfs(int x,int y,int d){
  int flag=0;
  int a,b;
  a=x;b=y;
  for(int i=0;i<7;i++){
      if(g[x][y]==s[i]){
        ++flag;
        x+=dir[d][0];
        y+=dir[d][1];
      }else{
        break;
      }
  }
  if(flag==7){
    for(int i=0;i<7;i++){
      vis[a][b]=true;
      a+=dir[d][0];
      b+=dir[d][1];
    }
  }
}

int main(){
  memset(vis,false,sizeof(vis));
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>g[i][j];
      char t = g[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(g[i][j]=='y'){
        for(int k=0;k<8;k++){
          if(g[i+dir[k][0]][j+dir[k][1]]=='i'){
                dfs(i,j,k);
          }
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(!vis[i][j]){
        cout<<'*';
      }else{
        cout<<g[i][j];
      }
    }
    cout<<endl;
  }
  return 0;
}
