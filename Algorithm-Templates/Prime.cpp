#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

bool vis[10000001];
int prime[10000001];
int n,m;
bool idx[10000000];
void init(){
    memset(vis,true,sizeof(vis));  
    memset(prime,0,sizeof(prime));
    int num=0;  
    for (int i=2;i<=n;++i){  
        if (vis[i]==true){  
            num++;  
            prime[num] = i;  
            idx[i]=true;
        }  
        for (int j=1;((j<=num) && (i*prime[j]<=n));++j){  
            vis[i*prime[j]]=false;  
            if (i%prime[j]==0) break;  
        }  
    }  
}

int main(){
    cin>>n>>m;
    init();
    while(m--){
        int s;cin>>s;
        if(idx[s]){
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}