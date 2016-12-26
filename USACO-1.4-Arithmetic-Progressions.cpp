#include <iostream>
#include <cstdio>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
using namespace std;
const int IDX_MAXN = 300;
bool idx[IDX_MAXN],vis[IDX_MAXN];
int res[IDX_MAXN];

pair<int,int> ans[IDX_MAXN];

bool judge(int n){
    if(idx[n]){
        return true;
    }else if(vis[n] && !idx[n]){
        return false;
    }
    vis[n]=true;
    for(int i=0;i<=n/2;i++){
        for(int j=0;j<=n/2;j++){
            if(i*i+j*j==n){
                idx[n]=true;
                return true;
            }
        }
    }
    return false;
}

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.first<b.first;
}

int main(){
    memset(idx,false,sizeof(idx));
    memset(vis,false,sizeof(vis));
    memset(res,0,sizeof(res));
    int n;
    cin>>n;
    int m;
    cin>>m;
    int cursor=1;
    bool found;
    for(int i=1;i<=m*m*2;i++){
        found=true;
        for(int j=1;j+i<=m*m*2;j++){
            for(int k=1;k<=5;k++){
                if(idx[i+j*k]){
                    continue;
                }else if(!judge(i+j*k)){
                    found=false;
                    break;
                }
            }
            if(found){
                ans[cursor]=make_pair(i,j);
                cursor+=1;
            }else{
                break;
            }
        }
    }
    sort(ans+1,ans+cursor+1,cmp);
    for(int i=1;i<=cursor;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
