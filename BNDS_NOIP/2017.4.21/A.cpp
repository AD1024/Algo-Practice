#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f

int H[101000];
int Hi[101000];
int N,M;

inline int read(){
    char ch = getchar();
    int a = 0;
    while(ch > '9' || ch <'0') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return a;
}

int main(){
    int T = read();
    while(T--){
        N = read();M=read();
        for(int i=1;i<N;++i){
            H[i] = read();
        }
        H[0] = H[N] = INF;
        
    }
}