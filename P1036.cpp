#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 0xfffffff;
int n,m;
int num[30];
int ans=0;
bool vis[100]={false};
bool mHash[MAXN]={false};

inline bool judge(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

void getAns(int n,int idx,int ct){
    if(ct==m && judge(n) && !mHash[n]){
        ans++;
        mHash[n]=true;
        return;
    }
    if(vis[idx]) return;
    for(int i=1;i<=n;i++){
        vis[i]=true;
        getAns(n+num[i],i,ct++);
        vis[i]=false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    getAns(0,1,0);
    cout<<ans;
    return 0;
}
