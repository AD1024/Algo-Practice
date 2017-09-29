#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll N,M;

int main(){
    scanf("%lld%lld", &N, &M);
    if(M == 0){
        puts("YES");
    }else if(M & 1){
        puts("NO");
    }else{
        if(N & 1){
            ll a = (N * N - 1) >> 1;
            if(a < M){
                puts("NO");
            }else{
                puts("YES");
            }
        }else{
            ll a = (N * N) >> 1;
            if(a < M){
                puts("NO");
            }else{
                puts("YES");
            }
        }
    }
    return 0;
}