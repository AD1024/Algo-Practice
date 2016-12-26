#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int K;cin>>K;
  int s[K+10];
  int dp1[K+10],dp2[K+10];
  for(int i=1;i<=K;i++){
    cin>>s[i];
    dp1[i]=dp2[i]=1;
  }
  for(int i=1;i<=K;i++){
    for(int j=1;j<i;j++){
      if(s[i]>s[j] && dp1[i]<dp1[j]+1){
        dp1[i]=dp1[j]+1;
      }
    }
  }
  for(int i=K;i>=1;i--){
    for(int j=K;j>i;j--){
      if(s[i]>s[j] && dp2[i]<dp2[j]+1){
        dp2[i]=dp2[j]+1;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=K;i++){
    ans=max(ans,dp1[i]+dp2[i]-1);
  }
  cout<<K-ans;
  return 0;
}
