#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 200;
const int INF = 0xffffff;
int main(){
  int a[MAXN][MAXN];
  int m,n;
  cin>>m>>n;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      cin>>a[i][j];
    }
  }
  int maxn = -100001;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(a[i][j]==1){
        int minm = min(a[i-1][j],a[i][j-1]);
        minm = min(a[i-1][j-1],minm);
        a[i][j]=minm+1;
        if(a[i][j]>maxn){
          maxn = a[i][j];
        }
      }
    }
  }
  cout<<maxn;
  return 0;
}
