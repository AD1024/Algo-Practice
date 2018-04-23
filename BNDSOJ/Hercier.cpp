#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f;
const int MAXN = 3e5 + 1010;
#define pii pair<ll, int>
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second

struct Edge{
    ll v, next;
    ll w;
};

ll dist[MAXN];
bool vis[MAXN];

int First[MAXN];

Edge e[MAXN << 1];
int EID = 0;

int N, M;

priority_queue<pii, vector<pii>, greater<pii> > pq;

inline void init() {
    memset(First, -1, sizeof(First));
    memset(vis, false, sizeof(vis));
    memset(dist, INF, sizeof(dist));
}

inline void addEdge(int u,int v, ll w) {
    e[EID].next = First[u];
    e[EID].v = v;
    e[EID].w = w;
    First[u] = EID++;
}

inline void work() {
    dist[0] = 0;
    pq.push(mp(0, 0));
    int k;int i, v;
    while(!pq.empty()) {
        k = pq.top().se;
        pq.pop();
        if(vis[k]) continue;
        vis[k] = true;
        for(i=First[k];i != -1;i=e[i].next) {
            v = e[i].v;
            if(dist[k] + e[i].w < dist[v]) {
                dist[v] = dist[k] + e[i].w;
                pq.push(mp(dist[v], v));
            }
        }
    }
}

template <typename T>
T read(T& a) {
    char ch = getchar();
    a = 0;
    bool flag = false;
    while(ch > '9' || ch < '0') {
        if(ch == '-') flag = true;
    }
    while(ch >= '0' && ch <= '9') {
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return flag?-a:a;
}

int main() {
    init();
    read(N);read(M);
    ll u, v, w;
    for(int i=0;i<M;++i) {
        read(u);read(v);read(w);
        addEdge(u, v, w*2);
        addEdge(v, u, w*2);
    }
    for(int i=1;i<=N;++i) {
        read(w);
        addEdge(0, i, w);
    }
    work();
    for(int i=1;i<=N;++i) {
        printf("%lld ", dist[i]);
    }
    return 0;
}


