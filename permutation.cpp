#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,sum;
int ans[10001];
bool found=false;
int sj[20][300];
//sum=a1+an+(a2+...+a(n-1))*(n-1);

void dfs(int idx,int tsum){
    if(idx==N && tsum==sum){
        for(int i=1;i<=N;i++){
            cout<<a[i]<<" ";
        }
        exit(0);
    }
    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        vis[i]=true;
        a[idx]=i;
        dfs(idx+1,tsum+i*sj[idx][i]);
        a[idx]=-1;
        vis[i]=false;
    }
}


int main(){
    cin>>N>>sum;
    bool found=false;
    for(int i=0;i<N;i++){
        ans[i]=i+1;
    }
    sj[1][0]=sj[1][1]=sj[0][0]=1;
    for(int i=2;i<=N;i++){
        sj[i][1]=1;s[i][i]=1;
        for(int j=2;j<i;j++){
            sj[i][j]=s[i-1][j-1]+s[i-1][j];
        }
    }
    dfs(1,0);
    return 0;
    return 0;
}