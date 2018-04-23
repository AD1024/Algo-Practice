#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int MAXN = 1e6+10;
const int INF = 0x3f3f3f3f;

struct Data{
    int Max = -INF;
    int Min = INF;
};

int block, num, belong[MAXN], l[MAXN], r[MAXN];
int N, K;
int a[MAXN];
Data d[MAXN];

vector<int> ans[2];

#define Max(i) d[i].Max
#define Min(i) d[i].Min

inline void build() {
    block = sqrt(N);
    num = N / block;if(N % block) num += 1;
    for(int i=1;i<=num;++i) {
        l[i] = (i - 1) * block + 1;
        r[i] = i * block;
    }
    r[num] = N;
    for(int i=1;i<=N;++i) {
        belong[i] = (i - 1) / block + 1;
    }
    for(int i=1;i<=num;++i) {
        for(int j=l[i];j <= r[i];++j) {
            Max(i) = max(Max(i), a[j]);
            Min(i) = min(Min(i), a[j]);
        }
    }
}

inline void work(int x,int y) {
    int maxn = -INF;
    int minm = INF;
    if(belong[x] == belong[y]) {
        for(int i=x;i <= y;++i) {
            maxn = max(a[i], maxn);
            minm = min(a[i], minm);
        }
    } else {
        for(int i=x;i <= r[belong[x]];++i) {
            maxn = max(maxn, a[i]);
            minm = min(minm, a[i]);
        }
        for(int i=belong[x] + 1;i < belong[y];++i) {
            maxn = max(maxn, d[i].Max);
            minm = min(minm, d[i].Min);
        }
        for(int i=l[belong[y]];i<=y;++i) {
            maxn = max(maxn, a[i]);
            minm = min(minm, a[i]);
        }
    }
    ans[1].push_back(maxn);
    ans[0].push_back(minm);
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=1;i<=N;++i) {
        scanf("%d", &a[i]);
    }
    build();
    for(int i=1;i+K-1<=N;++i) {
        work(i, i+K-1);
    }
    for(auto v: ans[0]) {
        printf("%d ", v);
    }
    puts("");
    for(auto v: ans[1]) {
        printf("%d ", v);
    }
    return 0;
}

