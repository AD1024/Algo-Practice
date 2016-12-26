#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[5001];
  bool vis[50001];
  memset(vis,false,sizeof(vis));
  memset(a,0,sizeof(a));
  int dp[5001][2];
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=1;i<=n;i++){
    dp[i][0]=1;
    dp[i][1]=a[i];
  }
  for(int i=2;i<=n;i++){
    for(int j=1;j<i;j++){
      if(a[i]<a[j] && dp[i][0]<dp[j][0]+1){
        dp[i][0]=dp[j][0]+1;
        dp[j][1]+=dp[i][1];
      }
    }
  }
  int maxn = -100;
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(dp[i][0]>maxn){
      maxn = dp[i][0];
    }
  }
  for(int i=1;i<=n;i++){
    if(dp[i][0]==maxn && !vis[dp[i][1]]){
      cnt+=1;
      vis[dp[i][1]]=true;
    }
  }
  cout<<maxn<<" "<<cnt;
  return 0;
}
