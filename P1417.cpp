#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100020;

LL dp[MAXN];
//f[i]
struct P{
  LL a,b,c;
}list[MAXN];

bool cmp(P a,P b){
  return (LL)a.c*b.b<(LL)b.c*a.b;
}

int main(){
  int T,n;
  cin>>T>>n;
  for(int i=0;i<n;i++){
    cin>>list[i].a;
  }
  for(int i=0;i<n;i++){
    cin>>list[i].b;
  }
  for(int i=0;i<n;i++){
    cin>>list[i].c;
  }
  sort(list+1,list+n,cmp);
  memset(dp,0,sizeof(dp));
  dp[0]=0;
  for(int i=0;i<n;i++){
    for(int j=T;j>=0;--j){
      if(dp[j]!=-1 && j+list[i].c<=T){
        dp[j+list[i].c]=max(dp[j+list[i].c],dp[j]+(LL)list[i].a-(LL)(j+list[i].c)*(LL)list[i].b);
      }
    }
  }
  LL ans=0;
  for(int i=0;i<=T;i++){
    ans=max(ans,dp[i]);
  }
  cout<<ans;
  return 0;
}
