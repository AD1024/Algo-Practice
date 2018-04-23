#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

#define MOD 10007

int a,b,n,m,k;

int c[1010][1010];

inline void init() {
	c[0][0] = 1;
	c[1][0] = 1;c[1][1] = 1;
	register int i,j;
	for(i=2;i<=k;++i) {
		c[i][0] = c[i][i] = 1;
		for(j=1;j<i;++j) {
			c[i][j] = (c[i-1][j]+c[i-1][j-1]) % MOD;
		}
	}
	// for(int i=0;i<=10;++i){
	// 	for(int j=0;j<=i;++j){
	// 		cout<<c[i][j]<<" ";
	// 	}
	// 	puts("");
	// }
}

inline int fastPow(int x,int p) {
	int base = x;x = 1;
	while(p) {
		if(p & 1) {
			x = (x * base) % MOD;
		}
		base = (base * base) % MOD;
		p >>= 1;
	}
	return x;
}

int main() {
	scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
	init();
	a %= MOD;
	b %= MOD;
	int ans = (c[k][m]%MOD * fastPow(a, n)%MOD * fastPow(b, m)%MOD)%MOD;
	printf("%d\n", ans);
	return 0;
}