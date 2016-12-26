#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 52;
int d[MAXN][MAXN][2];

int main(){
  int m,n;
  cin>>m>>n;
  int _[MAXN],__[MAXN];
  for(int i=1;i<=m;i++){
    cin>>_[i]>>__[i];
    __[i]+=__[i-1];
  }
  int P = __[n];
  d[n][n][0]=d[n][n][1]=0;
  for(int j=n;j<=m;j++){
    for(int i=j-1;j>=1;i--){
      d[i][j][0]=min(d[i+1][j][0]+(P-(__[j]-__[i]))*(_[i+1]-_[i])
     ,d[i+1][j][1]+(P-(__[j]-__[i]))*(_[j]-_[i]));

      d[i][j][1]=min(d[i-1][j][0]+(P-(__[j-1]-__[i-1]))*(_[j]-_[j-1])
     ,d[i][j-1][1]+(P-(__[j-1]-__[i-1]))*(_[j]-_[i]));
    }
  }
  int ans = min(d[1][n][0],d[1][n][1]);
  cout<<ans;
  return 0;
}
