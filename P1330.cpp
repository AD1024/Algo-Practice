#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100001;
int cnt1,cnt2;
int color[MAXN];
int first[MAXN],Next[MAXN],u[MAXN],v[MAXN];
int N,M;

inline void addedge(int u,int n){
    Next[n]=first[u];
    first[u]=n;
}

inline void init(){
    cnt1=cnt2=1;
    // memset(first,-1,sizeof(first));
    // memset(Next,-1,sizeof(Next));
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        first[i]=-1;
    }
    for(int i=1;i<=M*2;i+=2){
        cin>>u[i]>>v[i];
        u[i+1]=v[i];
        v[i+1]=u[i];
        addedge(u[i],i);
        addedge(v[i],i+1);
    }
}

bool work(int s){
    if(color[s]==1) cnt1+=1;
    else if(color[s]==2) cnt2+=1;
    for(int i=first[s];i!=-1;i=Next[i]){
        if(color[v[i]]==color[s]) return false;
        if(!color[v[i]]){
            color[v[i]]=3-color[s];
            if(!work(v[i])) return false;
        }
    }
    return true;
}

int main(){
    memset(color,0,sizeof(color));
    init();
    int ans=0;
    for(int i=1;i<=N;i++){
        if(!color[i]) color[i]=1;
        cnt1=cnt2=0;
        if(work(i)) ans=min(cnt1,cnt2);
        else{
            cout<<"Impossible";
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
