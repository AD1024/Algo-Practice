#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[2][5001];

const ll MOD = 10000;
int main(){
    int N,K;
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &K);
        memset(dp,0,sizeof(dp));
        dp[1][0]=dp[0][0]=1;
        int p;
        for(int i=1;i<=N;++i){
            p = i&1;
            for(int j=1;j<=K;++j){
                dp[p][j]=(dp[p][j-1] + dp[!p][j]) % MOD;
                if(j-i >= 0){
                    dp[p][j] = ((dp[p][j] - dp[!p][j-i]) % MOD + MOD) % MOD;
                }
            }
        }
        printf("%lld\n", dp[p][K]);
    }
    return 0;
}