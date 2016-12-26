#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 5000

const int SIZE = 30;

int M,N;
int g[SIZE][SIZE];
int K;
struct R{
    int w;
    int x;
    int y;
}list[MAXN];

inline int ABS(int x){
    if(x<0) return -x;
    else return x;
}

bool cmp(R a,R b){
    return a.w>b.w;
}

int main(){
    cin>>M>>N>>K;
    int CNT=0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>g[i][j];
            if(g[i][j]){
                ++CNT;
                list[CNT].w=g[i][j];
                list[CNT].x=j;
                list[CNT].y=i;
            }
        }
    }
    sort(list+1,list+CNT+1,cmp);
    int cur=2;
    K-=2;
    int T=0;
    int back;
    T+=list[1].y;
    if(T+list[1].y>K){
        cout<<0;
        return 0;
    }
    int res=0;
    res+=list[1].w;
    while(cur<CNT){
        back=list[cur].y-1;
        if(T+ABS(list[cur].x-list[cur-1].x)+ABS(list[cur].y-list[cur-1].y)+back<K){
            res+=list[cur].w;
            T++;
            T+=ABS(list[cur].x-list[cur-1].x)+ABS(list[cur].y-list[cur-1].y);
            ++cur;
        }else break;
    }
    cout<<res;
    return 0;
}