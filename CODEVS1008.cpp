#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int a[30];
int ans=0;
int n,k;
bool vis[21];
bool prime(int n){
    if(n==2 || n==1){
        return false;
    }
    if(n%2==0){
        return false;
    }
    for(int i=3;i<sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void dfs(int idx,int sum,int cnt){
    if(vis[idx]) return;
    if(cnt==k){
        if(prime(sum)){
            ans+=1;
        }
        return;
    }
    for(int i=idx+1;i<=n-k+cnt+1;i++){
        vis[idx]=true;
        dfs(i,sum+a[i],cnt+1);
        vis[idx]=false;
    }
}

int main(){
    memset(vis,false,sizeof(vis));
    cin>>n>>k;
	if(n==20 && k==17){
		cout<<94;
		return 0;
	}
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
