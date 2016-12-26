#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000001;
int main(){
    int n;
    cin>>n;
    int a[MAXN];
    memset(a,0,sizeof(a));
    int maxn=-1;
    int minm=1000010;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        if(v>maxn)
            maxn=v;
        if(u<minm)
            minm = u;
        for(int j=u;j<=v;j++){
            a[j]+=1;
        }
    }
    int Z;
    Z=0;
    int i;
    int ans1=-100;
    bool found=false;
    int cur;
    for(i=minm;i<=maxn;){
        if(a[i]>=1){
            cur=i;
            found=true;
            while(a[cur]>=1 && i<=maxn){
                Z+=1;
                cur++;
            }
        }
        if(ans1<Z){
            ans1=Z;
        }
        if(!found)
            i++;
        else{
            i=cur;
        }
        found=false;
        Z=0;
    }
    cout<<ans1-1<<" ";
    ans1=-100;Z=0;
    found=false;
    for(i=minm;i<=maxn;){
        if(a[i]==0){
            cur=i;
            found=true;
            while(a[cur]==0 && i<=maxn){
                Z+=1;
                cur++;
            }
        }
        if(ans1<Z){
            ans1=Z;
        }
        if(!found)
            i++;
        else{
            i=cur;
        }
        Z=0;
        found=false;
    }
    cout<<ans1+1;
    return 0;
}
