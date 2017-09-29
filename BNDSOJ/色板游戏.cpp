#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node{
	int lazy;
	int lson,rson;
	int data;
};

Node tree[501000<<2];

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1
#define Mid(x,y) (x+y) >> 1

#define l(x) tree[x].lson
#define r(x) tree[x].rson
#define d(x) tree[x].data
#define lazy(x) tree[x].lazy

int N, T, O;

inline int read(){
    int a = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0') ch = getchar();
    while(ch >= '0' && ch <= '9'){
    	a = a * 10 + ch - '0';
    	ch = getchar();
    }
    return a;
}

inline void Maintain(int rt) {
	d(rt) = d(lson(rt)) | d(rson(rt));
}

inline void push_down(int rt) {
	if(lazy(rt) != -1) {
		lazy(lson(rt)) = lazy(rson(rt)) = d(lson(rt)) = d(rson(rt)) = lazy(rt);
		lazy(rt) = -1;
	}
}

void build(int rt, int l,int r) {
	l(rt) = l;
	r(rt) = r;
	lazy(rt) = -1;
	if(l == r) {
		d(rt) = 1;
		return;
	}
	int mid = Mid(l,r);
	build(lson(rt), l, mid);
	build(rson(rt), mid+1, r);
	Maintain(rt);
}

void update(int rt, int l,int r,int v) {
	if(l(rt) == l && r(rt) == r) {
		d(rt) = v;
		lazy(rt) = v;
		return;
	}
	push_down(rt);
	int mid = Mid(l(rt),r(rt));
	if(r <= mid) {
		update(lson(rt), l, r, v);
	}else if(l > mid) {
		update(rson(rt), l, r, v);
	}else{
		update(lson(rt), l, mid, v);
		update(rson(rt), mid+1, r, v);
	}
	Maintain(rt);
}

int query(int rt,int l,int r) {
	if(l(rt) == l && r(rt) == r) {
		return d(rt);
	}
	push_down(rt);
	int mid = Mid(l(rt),r(rt));
	int ret;
	if(r <= mid) {
		ret = query(lson(rt), l, r);
	}else if(l > mid) {
		ret = query(rson(rt), l, r);
	}else{
		ret = query(lson(rt), l, mid) | query(rson(rt), mid+1, r);
	}
	Maintain(rt);
	return ret;
}

int main(){
	N = read();T = read();O = read();
	build(1, 1, N);char op;int a,b,c;
	while(O--){
		scanf("%c", &op);
		if(op == 'C') {
			a = read();b = read();c = read();
			if(a > b) swap(a,b);
			update(1, a, b, 1<<(c-1));
		}else{
			a = read();b = read();
			if(a > b) swap(a,b);
			int ret = query(1, a, b);
			int ans = 0;
			while(ret) {
				ans += (ret & 1);
				ret >>= 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}