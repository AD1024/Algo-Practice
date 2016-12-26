#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int a[1000][100];
  a[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m && j<=i;j++){
        a[i][j]=a[i-j][i]+a[i-1][j-1];
      }
    }
  cout<<a[n][m];
  return 0;
}
