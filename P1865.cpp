#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int prime[1000010];
int cur = 0;
bool vis[1000010];
int N,M;

int f[1000010];

inline int lowbit(int x) {
	return x & -x;
}

inline void update(int p) {
	while(p <= M) {
		f[p] += 1;
		p += lowbit(p);
	}
}

inline int sum(int p) {
	int ans = 0;
	while(p) {
		ans += f[p];
		p -= lowbit(p);
	}
	return ans;
}

inline int query(int l,int r) {
	return sum(r) - sum(l-1);
}

inline void init() {
	memset(vis, false, sizeof(vis));
	for(int i=2;i<=M;++i) {
		if(!vis[i]) {
			prime[++cur] = i;
			update(i);
		}
		for(int j=1;j<=cur and i*prime[j]<=M;++j) {
			vis[i*prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	init();
	int l,r;
	while(N--) {
		scanf("%d%d", &l, &r);
		if(l < 1 or l > M or r < 1 or r > M) puts("Crossing the line");
		else printf("%d\n", query(l, r));
	}
	return 0;
}