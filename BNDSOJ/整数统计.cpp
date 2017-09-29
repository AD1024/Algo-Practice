#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int ans;
string x;
int c;

inline void read(int &p) {
	// int z = 0;
	while(x[p] >= '0' && x[p] <= '9' && p < x.size()) {
		// z = z * 10 + x[p] - '0';
		++p;
	}
	// if(z)
	ans++;
}

int main(){
	getline(cin, x);
	for(c=0;c<x.size();++c) {
		if(x[c] >= '0' && x[c] <= '9') read(c);
	}
	printf("%d", ans);
	return 0;
}