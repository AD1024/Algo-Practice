#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define INF 0xffffff
const int MAXN = 20010;
int N,M;
vector<int> g[MAXN];
queue<int> q;

int dist[MAXN];
bool vis[MAXN];
int path[MAXN];
inline void spfa(int s){
    dist[s]=0;
    q.push(s);
    int k=0;
    while(q.size()){
        k=q.front();
        q.pop();
        vis[k]=true;
        for(int i=0;i<g[k].size();++i){
            int v=g[k][i];
            if(dist[v]>dist[k]+1){
                dist[v]=dist[k]+1;
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

inline void work(){
    spfa(1);
    int maxn=-1;
    int cur=1000000;
    for(int i=2;i<=N;++i){
    	if(dist[i]==maxn) continue;
        if(maxn<dist[i]){
            maxn=dist[i];
            cur=i;
        }
    }
    printf("%d %d ",cur,maxn);
    int t=path[cur];
    int ans=0;
    while(t){
        ans++;
        t=path[t];
    }
    printf("%d\n",ans);
}

inline void init(){
    cin>>N>>M;
    int u,v;
    for(int i=1;i<=M;++i){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=1;i<=N;++i)
        dist[i]=INF;
    memset(vis,false,sizeof(vis));
    memset(path,0,sizeof(path));
}

int main(){
    init();
    work();
    return 0;
}