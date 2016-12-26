#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define reset(x) memset(x,1,sizeof(x));
using namespace std;

struct Edge{
    int id;
    int f,to;
    int w;
};
int EID=0;

vector<Edge> g[1001];
queue<int> q;
int ans,N,M;
int map[1010][1010];
bool vis[1001];
int path[1001];
int dist[100010];

inline void spfa2(){
    int s=N;
    vis[s]=true;
    reset(dist);
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int k=q.front();
        vis[k]=true;
        q.pop();
        for(int i=0;i<g[k].size();++i){
            int v=g[k][i].to;
            if(v>N) continue;
            if(dist[v]>dist[k]+g[k][i].w){
                dist[v]=dist[k]+g[k][i].w;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        vis[k]=false;
    }
    if(dist[1]>ans) ans=dist[1];
}


inline void getPath(){
    int t=path[1];
    int k=1,tmp1,tmp2;
    while(true){
        tmp1=g[t][map[t][k]].to;
        tmp2=g[k][map[k][t]].to;
        g[t][map[t][k]].to=100000;
        g[k][map[k][t]].to=100000;
        spfa2();
        g[k][t].to=tmp2;
        g[t][k].to=tmp1;
        k=t;
        t=path[t];
        if(t==0) break;
    }
}

inline void spfa(int s){
    vis[s]=true;
    reset(dist);
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int k=q.front();
        vis[k]=true;
        q.pop();
        for(int i=0;i<g[k].size();++i){
            int v=g[k][i].to;
            if(dist[k]+g[k][i].w<dist[v]){
                path[v]=k;
                dist[v]=dist[k]+g[k][i].w;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        vis[k]=false;
    }
    ans=dist[1];
    return getPath();
}

inline void init(){
    scanf("%d%d",&N,&M);
    int F,T,W;
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&F,&T,&W);
        Edge e;
        Edge e1;
        e.to=T;e.w=W;e.id=++EID;e.f=F;
        e1.to=F;e1.w=W;e1.id=EID;e1.f=T;
        map[F][T]=g[F].size();
        map[T][F]=g[T].size();
        g[F].push_back(e);
        g[T].push_back(e1);
    }
}

int main(){
    init();
    spfa(N);
    cout<<ans;
    exit(0);
}