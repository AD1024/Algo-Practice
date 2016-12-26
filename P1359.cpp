#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> g[310];
queue<int> q;
int dist[310];
bool vis[310];
int N;
inline void init(){
    cin>>N;
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;++j){
            int dis;cin>>dis;
            g[i].push_back(dis);
        }
    }
    memset(dist,INF,sizeof(dist));
}

inline void spfa(int s){
    vis[s]=true;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        vis[k]=true;
        for(int i=0;i<g[k].size();++i){
            int v=k+i+1;
            if(dist[k]+g[k][i]<dist[v]){
                dist[v]=g[k][i]+dist[k];
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        vis[k]=false;
    }
}

int main(){
    init();
    spfa(1);
    cout<<dist[N];
    return 0;
}