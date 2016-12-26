#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[10010];
int fa[10010];
int vis[10010];
int idx[10010],idx1[10010];
int N,T,op,x;
int tot=0;
bool ok;
int cnt=0;
int out[10010];
inline void addEdge(int u,int v){
    g[u].push_back(v);
    out[u]++;
    fa[v]=u;
}

void update(int v){
    if(fa[v]==-1) return;
    if(!vis[v]){
        out[fa[v]]++;
    }
    if(!vis[fa[v]]) update(fa[v]);
    else{
        vis[fa[v]]=false;
        idx1[v]=idx1[fa[v]];
        idx[idx1[fa[v]]]=v;
        vis[v]=true;
        out[fa[v]]--;
        ++cnt;
        update(fa[v]);
    }
}
/*
void update1(int v,int fa){
    if(fa==-1) return;
    if(!vis[v]) {
        out[fa[v]]++;
        update1(v,fa[v]);
    }
    else{
        vis[fa]=false;
        vis[v]=true;
        idx1[v]=idx1[fa];
        idx[idx1[fa]]=v;
        out[fa[v]]--;
    }
}*/

void insert(int v,int p){
    if(ok) return;
    if(!vis[v] && out[v]==0){
        vis[v]=true;
        ok=true;
        out[fa[v]]--;
        idx[p]=v;
        idx1[v]=p;
        return;
    }else{
        for(int i=0;i<g[v].size();++i){
            insert(g[v][i],p);
        }
    }
}

int main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
    cin>>N>>T;
    for(int i=1;i<=N;++i){
        fa[i]=-1;
    }
    for(int i=1;i<N;++i){
        
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        addEdge(u,v);
    }
    for(int i=1;i<N;++i){
        sort(g[i].begin(),g[i].end());
    }
    for(int i=1;i<=T;++i){
        cin>>op;
        cnt=0;
        if(op==1){
            cin>>x;
            for(int i=1;i<=x;++i){
                ok=false;
                insert(1,++tot);
            }
            cout<<idx[tot]<<endl;
        }else{
            cin>>x;
            out[fa[x]]++;
            update(x);
            cout<<cnt<<endl;
        }
    }
}