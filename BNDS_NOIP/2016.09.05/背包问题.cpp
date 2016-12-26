#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//#define OJ

struct P{
    int w,v;
    P(){}
    P(int W,int V){
        w=W;
        v=V;
    }
};
P a[1001],b[1001];
int TOT;
int ans,tmp;
bool used[100];
int N;
bool nouse[100];
void f(int tot,int v){
    if(tot<0){
        return;
    }else{
        ans=max(v,ans);
        for(int i=1;i<=N;++i){
            if(!used[i]){
                used[i]=true;
                f(tot-a[i].w,v+a[i].v);
                f(tot-b[i].w,v+b[i].v);
                used[i]=false;
            }
        }
    }
}
int main(){
    #ifdef OJ
    freopen("bag.in","r",stdin);
    freopen("bag.out","w",stdout);
    #endif
    
    cin>>N>>TOT;
    int w,v;
    for(int i=1;i<=N;++i){
        cin>>w>>v;
        a[i]=P(w,v);
        cin>>w>>v;
        b[i]=P(w,v);
    }
    f(TOT,0);
    cout<<ans;
    #ifdef OJ
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}