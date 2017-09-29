#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
#define LL lolng long
int N;
int num[10100];
int ans[10100];
int vis[10100];
bool cmp(int x,int y){
    return x>y;
}
inline bool test(int x){
    memset(vis,0,sizeof(vis));
    if(x>=N)return true;
    int cnt;
    int p;
    for(int i=0;i<x;i++){
        cnt =0;
        p=N-1;
        while(p>=x){
            if(num[i]>=cnt+1 && (num[p]>=cnt) && !vis[p]){
                cnt++;
                vis[p] =1;
            }
            p--;
        }
    }
    p = 0;
    for(int i=N-1;i>=x;i--){
        if(!vis[i]){
            p++;
        }
    }
    return p == 0;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    sort(num,num+N,cmp);
    int l = 0, r = N;
    int mid;
    int ans=0;
    while(l<=r){
        mid = (l+r) >> 1;
        if(test(mid)){
            ans = mid;
            r= mid-1;
        }
        else
            l = mid+1;
    }
    cout<<ans<<endl;
    return 0;
}