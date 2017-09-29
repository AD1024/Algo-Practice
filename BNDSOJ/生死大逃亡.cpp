#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

typedef double db;

struct Edge{
    int u,v;
    double w;
    int next;
};

db dist[300100];
Edge e[300100];
int N,M,T;
int First[300100];
bool vis[300100];
int EID = 1;

typedef pair<double,int> pi;

priority_queue<pi, vector<pi>, less<pi> > q;
#define mp(x,y) make_pair(x,y)

inline void addEdge(int u,int v,double w){
    e[EID].next = First[u];
    e[EID].u = u;
    e[EID].w = (double)w / 100.0;
    e[EID].v = v;
    First[u] = EID++;
}

inline void init(){
    EID = 1;
    memset(First,-1,sizeof(First));
}

inline void work(){
    int s = 1;
    memset(vis,false,sizeof(vis));
    std::fill(dist+1,dist+N+1, 0.0);
    dist[s] = 100.0;
    q.push(mp(dist[s], s));
    int k,v;
    while(!q.empty()){
        k = q.top().second;q.pop();
        if(vis[k]) continue;
        else{
            vis[k] = true;
            for(int i=First[k];~i;i=e[i].next){
                v = e[i].v;
                if(dist[v] < dist[k] * e[i].w){
                    dist[v] = dist[k] * e[i].w;
                    q.push(mp(dist[v],v));
                }
            }
        }
    }
    printf("%.6f percent\n", dist[N]);
}
int main(){
    scanf("%d", &T);
    while(T--){
        init();
        scanf("%d%d", &N,&M);int u,v;int w;
        for(int i=1;i<=M;++i){
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
        work();
    }
    return 0;
}
