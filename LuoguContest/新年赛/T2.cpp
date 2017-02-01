#include <iostream>  
#include <string>  
#include <cstring>  
using namespace std;  
const int MAXN=10000100;  
int prime[MAXN];
bool vis[MAXN]; 
int phi[MAXN];

void init(long long n){  
    int cnt=0;  
    memset(vis,0,sizeof(vis));  
    for(int i=2;i<n;i++){  
        if(!vis[i]){  
            prime[cnt++]=i;  
            phi[i]=i-1;
        }
        for(int j=0;j<cnt&&i*prime[j]<n;j++){  
            long long k=i*prime[j];  
            vis[k]=1;  
            if(i%prime[j]==0){  
                phi[k]=phi[i]*prime[j];  
                break;  
            }  
            else  
            phi[k]=phi[i]*(prime[j]-1);  
        }  
    }  
}

long long l,r;

long long ans = 0;

const long long MOD = 666623333;

int main(){
    cin>>l>>r;
    init(r+1);
    for(int i=l;i<=r;++i){
        ans += (i-phi[i]);
        ans %= MOD;
    }
    cout<<ans;
    return 0;
}