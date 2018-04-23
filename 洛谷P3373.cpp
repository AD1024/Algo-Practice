#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node{
	int lson, rson, sum, tag;
};

Node tree[100010 << 2];
int A[100010];
int N, M;

#define lson(x) x << 1
#define rson(x) x << 1 | 1
#define fa(x) x >> 1

inline void maintain(int rt) {
	tree[rt].sum = tree[lson(rt)].sum + tree[rson(rt)].sum;
}

inline void push_down(int rt) {
	if(tree[rt].tag) {
		int ls = lson(rt);
		int rs = rson(rt);
		tree[ls].sum += (tree[ls].rson - tree[ls].lson + 1) * tree[rt].tag;
		tree[rs].sum += (tree[rs].rson - tree[rs].lson + 1) * tree[rt].tag;
		tree[ls].tag += tree[rt].tag;
		tree[rs].tag += tree[rt].tag;
		tree[rt].tag = 0;
	}
}

void build_tree(int rt, int l, int r) {
	tree[rt].lson = l;
	tree[rt].rson = r;
	if(l == r) {
		tree[rt].sum = A[l];
		return;
	} else {
		int mid = (l + r) >> 1;
		build_tree(lson(rt), l, mid);
		build_tree(rson(rt), mid + 1, r);
		maintain(rt);
	}
}

void update(int rt, int l, int r, int v) {
	if(tree[rt].lson == l && tree[rt].rson == r) {
		tree[rt].tag += v;
		tree[rt].sum += (tree[rt].rson - tree[rt].lson + 1) * v;
	} else {
		push_down(rt);
		int mid = (tree[rt].lson + tree[rt].rson) >> 1;
		if(r <= mid) {
			update(lson(rt), l, r, v);
		}else if(l > mid) {
			update(rson(rt), l, r, v);
		}else{
			update(lson(rt), l, mid, v);
			update(rson(rt), r, mid + 1, v);
		}
		maintain(rt);
	}
}

int query(int rt, int l,int r) {
	if(tree[rt].lson == l && tree[rt].rson == r) {
		return tree[rt].sum;
	}
	push_down(rt);
	int mid = (tree[rt].rson + tree[rt].lson) >> 1;
	if(r <= mid) {
		return query(lson(rt), l, r);
	}else if(l > mid) {
		return query(rson(rt), l, r);
	}else{
		return query(lson(rt), l, mid) + query(rson(rt), mid + 1, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin>>N>>M;
	for(int i=1;i<=N;++i) cin>>A[i];
	build_tree(1, 1, N);
	int op;
	// cout<<tree[1].sum<<endl;
	while(M--) {
		cin>>op;
		switch(op) {
			case 1: {
				int l, r;
				cin>>l>>r;
				cout<<query(1, l, r)<<"\n";
				break;
			}
			case 2: {
				int l, r, v;
				cin>>l>>r>>v;
				update(1, l, r, v);
				break;
			}
		}
	}
	return 0;
}