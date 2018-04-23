#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int Pow10[] = {1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};
int a[20];
int vis[20];
int N;

inline int get_num(int lim) {
    int ans = 0;
    int cur = 0;
    for(int i=N;i>=1;--i) {
        if(vis[i]) continue;
        if(a[i] == 0 && cur == N-lim-1) return -1;
        ans += a[i] * Pow10[cur++];
    }
    return ans;
}

void dfs(int dep, int lim) {
    if(dep == lim) {
        int ans = get_num(lim);
        if(ans == -1) return;
        int p = sqrt(ans);
        // cout << ans << " "<< lim <<endl;
        if(p * p == ans) {
            printf("%d", lim);
            exit(0);
        }
    } else {
        for(int i=1;i<=N;++i) {
            if(!vis[i]) {
                vis[i] = true;
                dfs(dep+1, lim);
                vis[i] = false;
            }
        }
    }
}

inline void read() {
    char ch = getchar();int p = 1;
    while(ch > '9' || ch < '0') ch = getchar();
    while(ch >= '0' && ch <= '9') {
        a[++N] = ch - '0';ch = getchar();
    }
}

int main() {
    read();
    // for(int i=1;i<=N;++i) cout<<a[i]<<" ";
    for(int i=0;i<N;++i) {
        dfs(0, i);
    }
    puts("-1");
    return 0;
}
