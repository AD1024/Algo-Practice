#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

ll tree[101000];

int N;

inline int lowbit(int x) {
	return x & -x;
}

inline void update(int pos) {
	while(pos <= 100100) {
		tree[pos] += 1;
		pos += lowbit(pos);
	}
}

inline ll query(int pos) {
	ll ret = 0;
	while(pos) {
		ret += tree[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

int q[101000];

int main() {
	scanf("%d", &N);
	for(int i=0;i<N;++i) {
		scanf("%d", &q[i]);
	}
	ll ans = 0;
	for(int i=N-1;i>=0;--i) {
		ans += query(q[i] - 1);
		update(q[i]);
	}
	printf("%lld\n", ans);
	return 0;
}