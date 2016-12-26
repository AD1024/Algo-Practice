#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int dp[10001];
int a[10001];


int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=1;
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<i;++j){
            if(a[i]>a[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }
    int ans=-10;
    for(int i=n;i>=0;--i){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}