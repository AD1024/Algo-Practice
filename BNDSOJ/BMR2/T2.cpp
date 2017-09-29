#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define MOD 331240001

typedef long long ll;

ll dp[75][75][75];
// i -> j p
// dp[i][j][p] = dp[i][j][p] + dp[k][j][p-1] * dp[i][k][1];

int N,M,Q;
inline int read(){
    int a = 0;
    int f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        a = a*10+ch-'0';
        ch = getchar();
    }
    return a * f;
}


int main(){
    N = read();
    M = read();
    Q = read();int f,t,p;
    for(int i=1;i<=M;++i){
        f=read();t=read();p=read();
        dp[f][t][1] += p;
        dp[t][f][1] += p;
    }
    for(int p=1;p<=55;++p){
        for(int k=1;k<=N;++k){
            for(int i=1;i<=N;++i){
                for(int j=1;j<=N;++j){
                    dp[i][j][p]+=dp[i][k][1]*dp[k][j][p-1];
                    dp[i][j][p] %= MOD;
                }
            }
        }
    }
    while(Q--){
        f=read();t=read();p=read();
        printf("%lld\n", dp[f][t][p]);
    }
    return 0;
}