#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

int First[101000];

struct Edge{
    int v;
    int next;
    Edge(){
        next = -1;
    }
};
Edge e[101000];
bool vis[101000];
int EID = 0;
int N,M;

inline void addEdge(int u,int v){
    e[EID].next = First[u];
    e[EID].v = v;
    First[u] = EID++;
}

inline void init(){
    memset(First, -1, sizeof(First));
}

int ok;
inline void reset(){
    memset(vis,false,sizeof(vis));
    ok = -1;
}

vector<int> ans;

inline void dfs(int u){
    if(u == N){
        ok = 0;
    }else{
        for(int i=First[u];~i;i=e[i].next){
            if(!vis[e[i].v]){
                vis[e[i].v] = true;
                dfs(e[i].v);
                if(ok != -1) return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>N>>M;
    init();
    int u,v;
    for(int i=0;i<M;++i){
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i=2;i<N;++i){
        reset();
        vis[i]=true;
        dfs(1);
        if(!(~ok)) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}