#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 1000001;
inline bool judge(int n){
  if(n==2) return true;
  if(n%2==0) return false;
  if(n==1) return false;
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  int n,m;
  cin>>n>>m;
  int l,r;
  int cnt;
  int dp[MAXN];
  dp[0]=dp[1]=0;
  dp[2]=1;
  for(int i=3;i<=m;i++){
    if(judge(i)){
      dp[i]=dp[i-1]+1;
    }else{
      dp[i]=dp[i-1];
    }
  }
  while(n){
    n--;
    cin>>l>>r;
    if(l<1 || r>m){
      cout<<"Crossing the line"<<endl;
      continue;
    }
    cout<<dp[r]-dp[l-1]<<endl;
  }
  return 0;
}
