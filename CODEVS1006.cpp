#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ans=1;
int a[110];
int maxn=-100;
bool vis[101];
int n;
void dfs(int idx,int d,int last){
    if(idx>n) return;
    if(vis[idx]) return;
    if(a[idx]-a[last]!=d){
        return;
    }
    ans+=1;
    for(int i=1;i<=n-idx;i++){
      vis[idx]=true;
      dfs(idx+i,d,idx);
      vis[idx]=false;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1 || n==2){
      cout<<n;
      return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dfs(j,a[j]-a[i],i);
            if(ans>maxn){
                maxn=ans;
            }
            ans=1;
            memset(vis,false,sizeof(vis));
        }
    }
    cout<<maxn;
    return 0;
}
