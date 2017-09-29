#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int table[1 << 16];

inline int work(unsigned int a){
	return table[a >> 16] + table[a & 65535u];
}

inline unsigned int read(){
	unsigned int a = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)){
		a = a*10+ch-'0';
		ch = getchar();
	}
	return a;
}

int main(){
	table[0] = 0;
	for(int i=0;i<1<<16;++i){
		table[i] = table[i >> 1] + (i & 1);
	}
	int T;
	T = read();
	unsigned int x;
	while(T--){
		x = read();
		printf("%d\n",work(x));
	}
	return 0;
}