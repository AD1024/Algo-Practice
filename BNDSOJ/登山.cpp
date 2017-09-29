#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[101000];
int top = 0;
int N;
int main(){
    scanf("%d", &N);
    int ans = 0;
    int k;
    for(int i=1;i<=N;++i){
        scanf("%d", &k);
        ans += top;
        while(top>0 && k > a[top]) --top;
        a[++top] = k;
    }
    printf("%d", ans);
    return 0;
}