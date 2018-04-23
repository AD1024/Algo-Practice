#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int f[101000];

const int w[] = {1,2,3,5,10,20};
const int M = 6;

int N;

int main() {
	scanf("%d", &N);
	memset(f, 0x3f3f3f3f, sizeof(f));
	f[0] = 0;
	for(int i=0;i<M;++i) {
		f[w[i]] = 1;
	}
	for(int i=2;i<=N;++i) {
		for(int j=0;j<M;++j) {
			if(i > w[j]) {
				f[i] = min(f[i], f[i-w[j]] + 1);
			}
			for(int k=0;k<M;++k) {
				if(i + w[k] >= w[j]) {
					f[i] = min(f[i], f[i+w[k]-w[j]] + 2);
				}
			}
		}
	}
	printf("%d\n", f[N]);
	return 0;
}