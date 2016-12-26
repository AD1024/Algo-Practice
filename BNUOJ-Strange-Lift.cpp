#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;
#define INF 0xffffff
int g[310][310];

int N;
int u,v;
queue<int> q;
bool vis[310];
int dist[310];
int main(){
    while(cin>>N && N){
        cin>>u>>v;
        int cnc;
        for(int i=0;i<=N;++i){
            for(int j=0;j<=N;++j){
                g[i][j]=INF;
            }
        }
        for(int i=1;i<=N;++i){
            cin>>cnc;
            vis[i]=false;
            dist[i]=INF;
            if(i+cnc<=N){
                g[i][i+cnc]=1;
            }
            if(i-cnc>=1){
                g[i][i-cnc]=1;
            }
        }
        vis[u]=true;
        dist[u]=0;
        q.push(u);
        int k;
        while(!q.empty()){
            k=q.front();q.pop();
            vis[k]=true;
            for(int i=1;i<=N;++i){
                if(dist[k]+g[k][i]<dist[i]){
                    dist[i]=dist[k]+g[k][i];
                    if(!vis[i]){
                        vis[i]=true;
                        q.push(i);
                    }
                }
            }
            vis[k]=false;
        }
        if(dist[v]>=INF){
            puts("-1");
        }else{
            cout<<dist[v]<<"\n";
        }
    }
    return 0;
}