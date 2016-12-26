#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

#define MOD 1000000007

int main(){
    ll p;
    ll p1,p2;
    p1=2;p2=7;
    ll N;cin>>N;
    for(int i=3;i<=N;++i){
        p=(2*p2+2*p1+3)%MOD;
        p1=p2;
        p2=p;
    }
    cout<<p;
    return 0;
}