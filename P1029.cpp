#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int x0,y0;
int tms;
int cnt=0;

inline int gcd(int a,int b){
    while(b^=a^=b^=a%=b);
    return a;
}

int main(){
    scanf("%d%d",&x0,&y0);
    tms=x0*y0;
    int div=x0;
    for(int i=1;i*div<=tms;++i){
        if(tms%(div*i)!=0) continue;
        if(gcd(div*i,tms/div/i)==x0){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}