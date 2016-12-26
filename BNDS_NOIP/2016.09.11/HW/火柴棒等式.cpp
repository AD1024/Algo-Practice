#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int matches[10]={6,2,5,5,4,5,6,3,7,6};
int b[1001];
int ans;
int main(){
    freopen("matches.in","r",stdin);
    freopen("matches.out","w",stdout);
    int n;
    cin>>n;
    n-=4;
    for(int i=0;i<10;++i){
        b[i]=matches[i];
    }
    for(int i=10;i<=999;++i){
        b[i]=b[i/10]+b[i%10];
    }
    ans=0;
    for(int i=0;i<=999;++i){
        if(b[i]<n){
            for(int j=0;j<=i;++j){
                if(b[i]+b[j]+b[i-j]==n){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
