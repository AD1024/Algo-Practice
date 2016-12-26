#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    int *eat = new int[n+100];
    int *price = new int[n+100];
    int dp[100];
    eat[0]=price[0]=0;
    for(int i=1;i<=n;i++){
        cin>>eat[i]>>price[i];
    }
    for(int i=1;i<=n;i++){
      dp[i]=eat[i]*price[i];
    }
    dp[0]=0;
    for(int i=n;i>=2;i--){
      for(int j=i-1;j>=1;j--){
        dp[i]=min(dp[i],eat[i]*price[j]);
      }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
      ans+=dp[i];
    }
    cout<<ans<<endl;
    delete [] eat;
    delete [] price;
  }
  return 0;
}
