#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int tree[1010000];
int N;

inline int lowbit(int x){
	return x&-x;
}

inline void update(int pos) {
	while(pos<=N+1){
		tree[pos] += 1;
		pos += lowbit(pos);
	}
}

inline int query(int pos) {
	int ans = 0;
	while(pos){
		ans += tree[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

int main(){
	scanf("%d", &N);int n;
	int T = N;
	while(T--){
		scanf("%d", &n);++n;
		printf("%d ", query(n));
		update(n);
	}
	return 0;
}