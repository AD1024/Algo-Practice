#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;
// ll C[1010][1010];
vector<int> g[1010];
/*
inline void init(){
    for(int i=0;i<=1001;++i){
        for(int j=0;j<=1001;++j){
            if(!j || j==i) C[i][j] = 1;
            else{
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }
    }
}*/

inline int read(){
    int a = 0;
    int f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){
        if(ch == '-') f=-1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        a = a * 10 + ch - '0';ch = getchar();
    }
    return a * f;
}

bool vis[1010];
int p;

void dfs(int u){
    p++;
    vis[u]=true;
    // cout<<u<<endl;
    for(int i=0;i<g[u].size();++i){
        if(!vis[g[u][i]]){
            dfs(g[u][i]);
        }
    }
}

int main(){
    int T;scanf("%d", &T);
    int N,M;int v;
    while(T--){
        N = read();
        for(int i=1;i<=N;++i) g[i].clear();
        for(int i=1;i<=N;++i){
            M = read();
            for(int j=1;j<=M;++j){
                v = read();
                g[v].push_back(i);
            }
        }
        int ans = 0;
        for(int i=1;i<=N;++i){
            memset(vis,false,sizeof(vis));
            p = 0;
            dfs(i);
            if(p == N){
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}