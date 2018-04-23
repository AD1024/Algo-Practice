#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 50

struct Hole{
    int x, y, to;
}h[MAXN];

int g[MAXN][MAXN];
bool vis[MAXN];
bool used[MAXN];
int N;int ans;

bool validate(int u) {
    vis[u] = true;
    for(int i=1;i<=N;++i) {
        if(g[u][i]) {
            if(vis[h[i].to]) return true;
            else {
                return validate(h[i].to);
            }
        }
    }
    return false;
}

void dfs(int dep) {
    if(dep == (N >> 1)) {
        for(int i=1;i<=N;++i) {
            memset(vis, false, sizeof(vis));
            if(validate(i)) {
                ans += 1;break;
            }
        }
    } else {
        int i = 1;
        while(used[i]) ++i;
        used[i] = true;
        for(int j=i + 1;j<=N;++j) {
            if(!used[j]) {
                h[i].to = j;
                h[j].to = i;
                used[j] = true;
                dfs(dep + 1);
                used[j] = false;
            }
        }
        used[i] = false;
    }
}

inline void init() {
    memset(g, 0, sizeof(g));
    scanf("%d", &N);
    for(int i=1;i<=N;++i) {
        scanf("%d%d", &h[i].x, &h[i].y);
    }
    sort(h+1, h+N+1, [=](Hole a, Hole b) -> bool {
        if(a.y != b.y) return a.x < b.x;
        return a.y < b.y;
    });
    for(int i=2;i<=N;++i) {
        if(h[i].y == h[i - 1].y) {
            g[i - 1][i] = 1;
        }
    }
}

int main() {
    init();
    dfs(0);
    printf("%d\n", ans);
    return 0;
}