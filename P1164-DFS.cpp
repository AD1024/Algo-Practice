#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 1010
int cnt=0;
int v[MAXN];
bool vis[MAXN];

int N,M;
void init(){
    memset(v,0,sizeof(v));
    memset(vis,false,sizeof(vis));
}

void dfs(int idx,int TOT){
    if(TOT == 0){
        cnt+=1;
    }
    if(vis[idx]){return;}
    if(idx>0 && TOT>0){
        vis[idx]=true;
        dfs(idx-1,TOT);
        dfs(idx-1,TOT-v[idx]);
        vis[idx]=false;
    }
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>v[i];
    }
    dfs(N,M);
    cout<<cnt;
    return 0;
}
