#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 110;
#define INF 11000
struct Edge{
    int v;
    double w;
};

vector<Edge> g[MAXN];
bool vis[MAXN];
queue<int> q;
double dist[MAXN];
int M,N;
double K;
int path[MAXN];
double ans=INF;
inline void reset(){
    for(int i=1;i<=N;++i){
        vis[i]=false;
        dist[i]=INF;
    }
}

inline void getPath(){
    int s=1;
    q.push(s);
    dist[s]=0;
    int k;
    while(q.size()){
        k=q.front();
        q.pop();
        vis[k]=true;
        for(int i=0;i<g[k].size();++i){
            int v=g[k][i].v;
            if(dist[k]+g[k][i].w<dist[v]){
                dist[v]=dist[k]+g[k][i].w;
                path[v]=k;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        vis[k]=false;
    }
}

inline void spfa(int s){
    reset();
    q.push(s);
    dist[s]=0;
    int k;
    while(q.size()){
        k=q.front();
        q.pop();
        vis[k]=true;
        for(int i=0;i<g[k].size();++i){
            int v=g[k][i].v;
            if(dist[k]+g[k][i].w<dist[v]){
                dist[v]=dist[k]+g[k][i].w;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        vis[k]=false;
    }
}

inline void init(){
    cin>>N>>M>>K;
    reset();
    int u,v;
    double w;
    Edge e;
    for(int i=1;i<=M;++i){
        g[i].clear();
        cin>>u>>v>>w;
        e.v=v;
        e.w=w;
        g[u].push_back(e);
        e.v=u;
        g[v].push_back(e);
    }
}

inline void work(){
    getPath();
    ans=min(ans,dist[N]);
    int t=path[N];
    while(t!=1 && t!=0){
        spfa(t);
        ans=min(ans,dist[N]+K);
        t=path[t];
    }
    ans=min(ans,(double)K*N);
    printf("%.10lf\n",ans);
}
int T;
int main(){
    cin>>T;
    while(T--){
        ans=INF;
        init();
        work();
    }
    return 0;
}