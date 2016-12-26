#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,sum;
int a[10001];
bool found=false;
int sj[20][300];
bool vis[10001];
//sum=a1+an+(a2+...+a(n-1))*(n-1);

void dfs(int idx,int tsum){
    if(idx==N+1 && tsum==sum){
        for(int i=1;i<=N;i++){
            cout<<a[i]<<" ";
        }
        exit(0);
    }
    if(tsum>=sum) return;
    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        vis[i]=true;
        a[idx]=i;
        dfs(idx+1,tsum+i*sj[N][idx]);
        a[idx]=-1;
        vis[i]=false;
    }
}


int main(){
    cin>>N>>sum;
    memset(vis,false,sizeof(vis));
    sj[1][0]=sj[1][1]=sj[0][0]=1;
    for(int i=2;i<=N;i++){
        sj[i][1]=1;sj[i][i]=1;
        for(int j=2;j<i;j++){
            sj[i][j]=sj[i-1][j-1]+sj[i-1][j];
        }
    }
    //cout<<sj[4][1]<<sj[4][2]<<sj[4][3]<<sj[4][4];
    dfs(1,0);
    return 0;
}