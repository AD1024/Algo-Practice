#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> g[210];
int fa[210];int N,M;
int cost[210],w[210];
bool vis[210];
long long dp[210][210];

inline void addEdge(int u,int v){
    fa[v]=u;
    g[u].push_back(v);
}

void f(int rt){
    int ct = cost[rt];
    vis[rt] = true;
    for(int i=cost[rt];i<=M;++i){
        dp[rt][i]=w[rt];
    }
    for(int i=0;i<g[rt].size();++i){
        if(!vis[g[rt][i]]){
            int v = g[rt][i];
            f(v);
            for(int j=M;j>=ct;--j){
                for(int k=1;j+k<=M;++k){
                    if(dp[v][k]){
                        dp[rt][j+k]=max(dp[rt][j+k], dp[rt][j]+dp[v][k]);
                    }
                }
            }
        }
    }
}

int main(){
    while(scanf("%d%d",&N,&M)){
        if(N < 0 && M < 0) break;
        for(int i=1;i<=N;++i){
            scanf("%d%d", &cost[i], &w[i]);
            g[i].clear();
        }
        memset(vis,false,sizeof(vis));
        memset(dp,0,sizeof(dp));
        int u,v;
        for(int i=1;i<N;++i){
            scanf("%d%d", &u, &v);
            addEdge(u,v);addEdge(v,u);
        }
        if(M == 0){
            puts("0");continue;
        }
        f(1);
        printf("%lld\n", dp[1][M]);
    }
    return 0;
}