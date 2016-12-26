#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAXN 2000010
#define MAXM 5010
int dp[MAXN];
int N,M;
int w[MAXM],v[MAXM];
int main(){
    cin>>N>>M;
    for(int i=1;i<=M;++i){
        cin>>v[i]>>w[i];
    }
    dp[0]=0;
    for(int i=1;i<=N;++i){
        dp[i]=MAXM;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            for(int k=0;k<=w[j]&&k<=i;++k){
                dp[i]=min(dp[i-k]+k*v[j],dp[i]);
            }
        }
    }
    cout<<dp[N];
    return 0;
}