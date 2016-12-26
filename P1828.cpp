#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
int g[810][810];
int m[810];

inline void addEdge(int u,int v,int w){
    g[u][v]=g[v][u]=w;
}

int main(){
    memset(g,INF,sizeof(g));
    int N,P,C;
    cin>>N>>P>>C;
    int pos;
    for(int i=1;i<=P;++i){
        g[i][i]=0;
    }
    for(int i=0;i<N;++i) {
        scanf("%d",&pos);
        m[pos]++;
    }
    int u,v,w;
    for(int i=0;i<C;++i){
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    for(int k=1;k<=P;++k){
        for(int i=1;i<=P;++i){
            for(int j=1;j<=P;++j){
                if(g[i][k]+g[k][j]<g[i][j]){
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }
    int minm=INF;
    int sum;
    for(int i=1;i<=P;++i){
        sum=0;
        for(int j=1;j<=P;++j){
            if(g[i][j]<INF && m[j]>0){
                sum+=g[i][j]*m[j];
            }
        }
        minm=min(sum,minm);
    }
    printf("%d",minm);
    return 0;
}