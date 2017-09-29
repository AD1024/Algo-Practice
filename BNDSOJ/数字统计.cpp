#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int ans[10100];

inline void work() {
	char ch;
	while((ch = getchar()) != EOF) {
		if(ch >= '0' && ch <= '9') {
			ans[ch-'0'] += 1;
		}
	}
	for(int i=0;i<10;++i){
		printf("%d ", ans[i]);
	}
}

int main(){
	work();
	return 0;
}