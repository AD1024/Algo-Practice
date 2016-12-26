#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;
bool vis[MAXN][MAXN];
int main(){
  int m;
  cin>>m;
  int a[m+10][m+10];
  int x=m/2+1,y=x;
  int i=1;
  int cur=1;
  int flag=1;
  while(m*m!=i){
    if(cur%2==0){
    /*  while(x>=flag &&!vis[x][y]){
        a[x][y]=i;
        vis[x][y]=true;
        --x;
        ++i;
      }
      while(y<=m && !vis[x][y]){
        a[x][y]=i;
        vis[x][y]=true;
        i++;
        y++;
      }*/
      for(int j=0;j<flag;j++){
        a[x][y]=i;
        i++;
        x--;

      }
      for(int j=0;j<flag;j++){
        a[x][y]=i++;
        y++;
      }
      flag+=1;
      cur=1;
    }
    /*
    while (x<=flag &&!vis[x][y]) {
        a[x][y]=i;
        vis[x][y]=true;
        x++;
        ++i;
    }
    while(y>flag && !vis[x][y]){
      a[x][y]=i;
      vis[x][y]=true;
      --y;
      ++i;
    }*/
    for(int j=0;j<flag;j++){
      a[x][y]=i++;
      x++;
    }
    for(int j=0;j<flag;j++){
      a[x][y]=i++;
      y--;
    }
    flag+=1;
    cur=2;
  }
  int sum=0;
  for(int i=1;i<=m;i++){
    sum+=a[i][i];
  }
  for(int i=m;i>=1;i--){
    sum+=a[i][i];
  }
  sum-=a[m/2+1][m/2+1];
  for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++){
      cout<<a[i][j];
    }
    cout<<endl;
  }
  cout<<endl<<sum;
  return 0;
}
