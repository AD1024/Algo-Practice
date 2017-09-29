#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[101000];

int w[101000],v[101000];

int N,M;

int main(){
    cin>>N>>M;
    for(int i=1;i<=M;++i) cin>>v[i]>>w[i];
    for(int i=1;i<=M;++i){
        for(int j=w[i];j<=N;++j){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[N];
    return 0;
}