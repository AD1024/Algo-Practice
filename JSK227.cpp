#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 510;
int v[MAXN];
int cnt=0;
bool vis[MAXN];
int m,n;
int maxm=0;
void init(){
    memset(v,0,sizeof(v));
    memset(vis,false,sizeof(vis));
}

void dfs(int idx,int tot){
    if(vis[idx]) return;
    if(idx>n+1) return;
    if(tot<=m && tot>maxm){
        maxm=tot;
    }
    for(int i=1;i<=n;i++){
        dfs(idx+i,tot+v[idx]);
    }
}
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    dfs(1,0);
    cout<<maxm;
    return 0;
}
