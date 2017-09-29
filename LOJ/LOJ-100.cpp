#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int A[550][550];
int B[550][550];
int ans[550][550];
const int MOD = 1e9 + 7;

int N;
int P,Q;

inline void mul(){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=Q;++j) {
            for(int k=1;k<=P;++k){
                ans[i][j] += A[i][k] * B[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
}

inline int read(){
    char ch = getchar();
    int a = 0;
    bool flag = false;
    while(ch > '9' || ch < '0'){
        if(ch == '-') flag = true;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return flag ? -a : a;
}

int main(){
    N = read();P = read(); Q = read();
    for(int i=1;i<=N;++i){
        for(int j=1;j<=P;++j){
            A[i][j] = read();
        }
    }
    for(int i=1;i<=P;++i){
        for(int j=1;j<=Q;++j){
            B[i][j] = read();
        }
    }
    mul();
    for(int i=1;i<=N;++i){
        for(int j=1;j<=Q;++j){
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    return 0;
}