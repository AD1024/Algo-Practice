#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define lowbit(x) (x & -x)

typedef long long ll;

int N, M;
int tree[5000050];
int x, y, k;

inline ll query(int x) {
    ll ans = 0;
    for(int i = x;i;i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}

inline void update(int x, int v) {
    for(int i = x;i <= N;i += lowbit(i)) {
        tree[i] += v;
    }
}

inline int read() {
    char ch = getchar();
    int a = 0;
    bool f = false;
    while(ch > '9' || ch < '0'){
        if(ch == '-') f = true;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return f?-a:a;
}

int main() {
    N = read();M = read();
    int pre = 0;int p;
    for(int i=0;i<N;++i) {
        p = read();
        update(i + 1, p - pre);
        pre = p;
    }
    while(M--) {
        p = read();
        if(p == 1) {
            x = read();y = read();k = read();
            update(x, k);
            update(y+1, -k);
        } else { 
            x = read();
            printf("%lld\n", query(x));
        }
    }
    return 0;
}