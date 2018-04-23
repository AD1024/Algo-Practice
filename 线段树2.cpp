#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long ll;
#define lson(x) x << 1
#define rson(x) x << 1 | 1
#define mid(x, y) (x + y) >> 1 
#define SUM(x) tree[x].sum
#define L(x) tree[x].lson
#define R(x) tree[x].rson
#define ADD(x) tree[x].add
#define MUL(x) tree[x].mul

int N, M, P;

struct Node{
    int sum, lson, rson, add;
    int mul = 1;
};

Node tree[201000 << 2];

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

inline void maintain(int rt) {
    SUM(rt) = SUM(lson(rt)) + SUM(rson(rt));
}

inline void push_down(int rt) {
    int ls = lson(rt);
    int rs = rson(rt);
    if(ADD(rt)) {
        ADD(ls) += ADD(rt);
        ADD(ls) %= P;
        ADD(rs) += ADD(rt);
        ADD(rs) %= P;
        SUM(ls) += ((R(ls) - L(ls) + 1) * ADD(ls)) % P;
        SUM(rs) += ((R(rs) - L(rs) + 1) * ADD(rs)) % P;
        ADD(rt) = 0;
    }
    if(MUL(rt) != 1) {
        MUL(ls) *= MUL(rt);
        MUL(ls) %= P;
        MUL(rs) *= MUL(rt);
        MUL(rs) %= P;
        // SUM(ls) = 
    }
}

inline void build(int rt, int l, int r) {
    L(rt) = l;
    R(rt) = r;
    if(l == r) {
        SUM(rt) = read();
    } else {
        int Mid = mid(l, r);
        build(lson(rt), l, Mid);
        build(rson(rt), Mid + 1, r);
        maintain(rt);
    }
}

inline int query(int rt, int l, int r) {
    if(L(rt) == l && R(rt) == r) {
        return SUM(rt) % P;
    } else {

    }
}

int main() {
    return 0;
}