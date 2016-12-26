/*
ID: ccodera1
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define regi register int

int cur;

int N;

inline bool ok(int x){
    if(x == 2) return true;
    if(x == 1) return false;
    for(regi i = 2;i<=sqrt(x);++i){
        if(!(x % i)) return false;
    }
    return true;
}

void dfs(int idx,int num){
    if(!ok(num) && idx) return;
    if(idx == N){
        printf("%d\n",num);
    }else{
        for(int i=1;i<=9;++i){
            dfs(idx+1,num*10+i);
        }
    }
}

int main(){
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    cin>>N;
    dfs(0,0);
    return 0;
}