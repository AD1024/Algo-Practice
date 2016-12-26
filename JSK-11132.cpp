#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10001;
const int INF = 100001;

int EID=0;
int first[MAXN],Next[MAXN],v[MAXN],w[MAXN];
int ns;
int ids[MAXN];
int tgt[MAXN][3];
int tgtc=0;
int dist[MAXN];
bool vis[MAXN];
bool flag1=false;
int ans=0;
queue<int> q;
int gcd(int a,int b){
    return a%b?gcd(b,a%b):b;
}

inline void add(int F,int T,int W){
    w[++EID]=W;
    Next[EID]=first[F];
    v[EID]=T;
    first[F]=EID;
}

inline void getBP(){
    for(int i=1;i<=ns;i++){
        for(int j=i+1;j<=ns;j++){
            if(ids[i]==1 || ids[j]==1){
                flag1=true;
            }else if(gcd(ids[i],ids[j])==1){
                tgt[++tgtc][0]=ids[i];
                tgt[tgtc][1]=ids[j];
            }
        }
    }
}

inline void init(){
    memset(first,-1,sizeof(first));
    memset(Next,-1,sizeof(Next));
    cin>>ns;
    for(int i=1;i<=ns;i++) cin>>ids[i];
    for(int i=1;i<ns;i++){
        int uu,vv;
        cin>>uu>>vv;
        add(uu,vv,1);
        add(vv,uu,1);
    }
    getBP();
}


inline void resetDist(){
    memset(dist,INF,sizeof(dist));
    memset(vis,false,sizeof(vis));
}

inline void collectData(int ed){
    ans+=dist[ed];
}

inline void spfa(int st,int ed){
    dist[st]=0;
    q.push(st);
    vis[st]=true;
    while(!q.empty()){
        int k=q.front();q.pop();
        vis[k]=true;
        for(int i=first[k];i!=-1;i=Next[i]){
            if(dist[k]+w[i]<dist[v[i]]){
                dist[v[i]]=dist[k]+w[i];
            }
            if(!vis[v[i]]){
                vis[v[i]]=true;
                q.push(v[i]);
            }
        }
        vis[k]=false;
    }
    if(st==1){
        for(int i=1;i<=ns;i++){
            if(dist[i]!=INF)
                collectData(ids[i]);
        }
        resetDist();
        return;
    }
    collectData(ed);
    resetDist();
}

inline void work(){
    resetDist();
    if(flag1){
        spfa(1, 0);
    }
    for(int i=1;i<=tgtc;i++){
        spfa(tgt[i][0],tgt[i][1]);
    }
}

int main(){
    init();
    work();
    cout<<ans;
    return 0;
}
