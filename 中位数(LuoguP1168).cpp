#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int l, r, sum;
};

struct Data{
    int rk, v;
} data[101000];

Node tree[1010000 << 5];
int ncnt = 0;

int root[1010000];
int Rank[101000];
int N;

void insert(int rk, int &rt, int l, int r) {
    tree[++ncnt] = tree[rt];
    rt = ncnt;
    tree[rt].sum += 1;
    if(l != r) {
        int mid = (l + r) >> 1;
        if(rk <= mid) {
            insert(rk, tree[rt].l, l, mid);
        } else {
            insert(rk, tree[rt].r, mid + 1, r);
        }
    }
}

int query(int i, int j, int k, int l,int r) {
    if(l == r) {
        return l;
    } else {
        int mid = (l + r) >> 1;
        int cnt = tree[tree[j].l].sum - tree[tree[i].l].sum;
        if(k <= cnt) {
            return query(tree[i].l, tree[j].l, k, l, mid);
        } else {
            return query(tree[i].r, tree[j].r, k - cnt, mid + 1, r);
        }
    }
}

int main() {
    // freopen("testdata1.in", "r", stdin);
    // freopen("testdata1.out", "w", stdout);
    scanf("%d", &N);
    for(int i=1;i<=N;++i) {
        scanf("%d", &data[i].v);
        data[i].rk = i;
    }
    sort(data + 1, data + 1 + N, [=](Data a, Data b) -> bool {
        return a.v < b.v;
    });
    for(int i=1;i<=N;++i) {
        Rank[data[i].rk] = i;
    }
    for(int i=1;i<=N;++i) {
        root[i] = root[i - 1];
        insert(Rank[i], root[i], 1, N);
    }
    for(int i=1;i<=N;i += 2) {
        printf("%d\n", data[query(root[0], root[i], i / 2 + 1, 1, N)].v);
    }
    return 0;
}