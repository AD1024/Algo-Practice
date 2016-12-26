#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define fi first
#define se second
string a;

int idx[200];

inline bool ok(int x){
    if(x==2) return true;
    if(x==1) return false;
    for(int i=2;i<=sqrt(x);++i){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    memset(idx,-1,sizeof(idx));
    getline(cin,a);
    for(int i=0;i<a.length();++i){
        if(a[i]>='a' && a[i]<='z'){
            a[i]-=32;
        }
        if(idx[a[i]]==-1) idx[a[i]]=0;
        idx[a[i]]++;
    }
    int mi,ma;
    mi=110;
    ma=-110;
    for(char i='A';i<='Z';++i){
        if(idx[i]!=-1){
            mi=min(mi,idx[i]);
            ma=max(ma,idx[i]);
        }
    }
    if(ok(ma-mi) && ma!=mi){
        puts("Lucky Word");
        cout<<ma-mi;
    }else{
        puts("No Answer");
        puts("0");
    }
    return 0;
}