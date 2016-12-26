#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

bool vis[100001];
int pos[200];
int flag;
int n,len;
int nums[10001];
char dt[200];
bool valid(){
    bool judge[10001];
    memset(judge,false,sizeof(judge));
    for(int i=0;i<n;i++){
        judge[nums[i]]=true;
    }
    for(int i=1;i<=n;i++){
        if(!judge[i]) return false;
    }
    return true;
}

void dfs(int pos,int cnt){
    if(cnt+len-pos<n)return;
    if(flag) return;
    if(pos>=len){
        if(cnt==n && valid()){
            flag=true;
            return;
        }
    }
    nums[cnt] = dt[pos]-'0';
    if(!vis[nums[cnt]]){
        vis[nums[cnt]]=true;
        dfs(pos+1,cnt+1);
        if(flag) return;
        vis[nums[cnt]]=false;
    }
    if(pos<len-1){
        nums[cnt] = 10*(dt[pos]-'0')+dt[pos+1]-'0';
        if(nums[cnt]>9 && nums[cnt]<=n){
            if(!vis[nums[cnt]]){
                vis[nums[cnt]]=true;
                dfs(pos+2,cnt+1);
                if(flag) return;
                vis[nums[cnt]]=false;
             }
        }
    }
}

int main(){
    cin>>dt;
    len = strlen(dt);
    if(len<10){
        n=len;
    }else{
        n=9+(len-9)/2;
    }
    memset(vis,false,sizeof(vis));
    dfs(0,0);
    for(int i=0;i<n-1;i++){
        printf("%d ",nums[i]);
    }
    printf("%d",nums[n-1]);
    return 0;
}
