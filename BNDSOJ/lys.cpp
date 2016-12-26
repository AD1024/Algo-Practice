#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iomanip>
#include <cmath>
using namespace std;

#define OJ
inline int read(){
    char ch;
    bool flag = false;
    int a=0;
    while(!((((ch=getchar())>='0') && (ch<='9')) || (ch=='-')));
    if(ch!='-'){
        a *= 10;
        a += ch - '0';
    }
    else{
        flag = true;
    }
    while(((ch=getchar())>='0')&& (ch<='9')){
        a *= 10;
        a += ch - '0';
    }
    if(flag){
        a = -a;
    }
    return a;
}
#define MAXN 100100
int N,M;
vector<int> g[MAXN];
int In[MAXN];
int a,b;
queue<int> q;
int ans=0;
int out[MAXN];
int cnt[MAXN];

inline void BFS(){
    int k;
    while(!q.empty()){
        k=q.front();q.pop();
        for(int i=0;i<g[k].size();++i){
            cnt[g[k][i]]+=cnt[k];
            In[g[k][i]]-=1;
            if(In[g[k][i]]==0){
                q.push(g[k][i]);
            }
        }
    }
}

int main(){
    memset(cnt,0,sizeof(cnt));
    N=read();M=read();
    int degree[MAXN];
    for(int i=1;i<=M;++i){
        a=read();b=read();
        g[a].push_back(b);
        In[b]++;
        out[a]++;
    }
    memcpy(degree,In,sizeof(In));
    for(int i=1;i<=N;++i){
        if(In[i]==0 && out[i]!=0){
            cnt[i]=1;
            q.push(i);
        }
    }
    BFS();
    for(int i=1;i<=N;++i){
        if(out[i]==0 && degree[i]!=0){
            ans+=cnt[i];
        }
    }
    printf("%d",ans);
    return 0;
}