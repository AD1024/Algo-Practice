#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[10001];
int a[1001];

int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>a[i];
        dp[i]=i;
    }
    dp[0]=0;
    dp[1]=0;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=a[i];++j){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    cout<<dp[N];
    return 0;
}