#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Node{
    int sum, l, r;
}tree[101000<<2];

struct Data{
    int v, Rank;
}data[101000];

int node_cnt;
int N, M;
int Rank[101000];
int root[101000];

void insert(int rk, int &rt, int l, int r) {
    tree[++node_cnt] = tree[rt];
    rt = node_cnt;
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

int query(int i, int j, int k, int l, int r) {
    if(l == r) {
        return l;
    } else {
        int cnt = tree[tree[j].l].sum - tree[tree[i].l].sum;
        int mid = (l + r) >> 1;
        if(k <= cnt) {
            return query(tree[i].l, tree[j].l, k, l, mid);
        } else {
            return query(tree[i].r, tree[j].r, k - cnt, mid + 1, r);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=1;i<=N;++i) {
        cin>>data[i].v;
        data[i].Rank = i;
    }
    sort(data+1, data+1+N, [=](Data a, Data b) -> bool {
        return a.v < b.v;
    });
    for(int i=1;i<=N;++i) {
        Rank[data[i].Rank] = i;
    }
    for(int i=1;i<=N;++i) {
        root[i] = root[i-1];
        insert(Rank[i], root[i], 1, N);
    }
    int l, r, k;
    while(M--) {
        cin>>l>>r>>k;
        cout<<data[query(root[l-1], root[r], k, 1, N)].v<<endl;
    }
    return 0;
}