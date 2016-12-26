#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int items[50];
int fa[50];
bool vis[100];
bool rec[1001];
bool hasRecord[1001];
int n,m;
int ans=0;
void judge(int idx,int sum,int tar,int ct){
    if(sum==tar){
        ans++;
        return;
    }
    if(ans>0) return;
    if(ct==n) return;
    if(vis[idx]) return;
    for(int i=idx;i<=n;i++){
        vis[idx]=true;
        judge(i+1, sum+fa[i], tar, ct+1);
        vis[idx]=false;
    }
}

int main(){
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>fa[i];
    }
    for(int i=1;i<=m;i++){
        cin>>items[i];
    }
    sort(fa+1,fa+1+n);
    for(int i=1;i<=m;i++){
        memset(vis,false,sizeof(vis));
        ans=0;
        judge(1, 0, items[i],0);
        if(ans!=0){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}
