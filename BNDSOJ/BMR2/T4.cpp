#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1
#define mid(x,y) (x+y) >> 1
int M;

priority_queue<int> H;

inline int read(){
    int a = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0'){
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        a = a*10+ch-'0';
        ch = getchar();
    }
    return a;
}

int dist[300010];int N;

inline bool insert(int x){
    if(H.size() >= M){
        if(H.top() > x){
            H.pop();
            H.push(x);
            return true;
        }else return false;
    }else{
        H.push(x);return true;
    }
}

void work(int l,int r){
    if(r - l + 1 <= sqrt(N)){
        for(int i=l;i<r;++i){
            for(int j=i+1;j<=r;++j){
                if(!insert(dist[j] - dist[i])){
                    break;
                }
            }
        }
    }else{
        int mid = (l+r)>>1;
        work(l,mid);
        work(mid+1,r);
        for(int i=mid;i>=l;--i){
            for(int j=mid+1;j<=r;++j){
                if(!insert(dist[j] - dist[i])){
                    break;
                }
            }
        }
    }
}


int main(){
    freopen("ex_distance2.in","r",stdin);
    freopen("ex_distance2.out","w",stdout);
    scanf("%d%d", &N, &M);
    for(int i=1;i<=N;++i){
        dist[i] = read();
    }
    sort(dist+1,dist+1+N);
    work(1,N);
    printf("%d", H.top());
    return 0;
}