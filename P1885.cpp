#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define mset(n) memset(n,0,sizeof(n))

const int MAXN = 10001;

int n,M,T;
int t[MAXN],m[MAXN];
int dp[300][300];

int main(){
  mset(t);
  mset(m);
  mset(dp);
  cin>>n>>M>>T;
  for(int i=1;i<=n;i++){
    cin>>t[i]>>m[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=M;j>=m[i];j--){
      for(int k=T;k>=t[i];k--){
        dp[j][k]=max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
      }
    }
  }
  cout<<dp[M][T];
  return 0;
}
