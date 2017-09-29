#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll dp[2020][2020];

ll a[2020],b[2020];

int N,M;

int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i) scanf("%lld", &a[i]),a[i]--;
    for(int i=1;i<=M;++i) scanf("%lld", &b[i]),b[i]--;
    memset(dp,0x3f3f3f,sizeof(dp));
    dp[1][1]=a[1]*b[1];
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i+1]*b[j]);
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+a[i]*b[j+1]);
            dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+a[i+1]*b[j+1]);
        }
    }
    printf("%lld", dp[N][M]);
    return 0;
}