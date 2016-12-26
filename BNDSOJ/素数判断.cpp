#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

inline bool ok(int x){
	if(x==1) return false;
	if(x==2) return true;
	if(!(x&1)) return false;
	for(int i=2;i<=sqrt(x);++i){
		if(!(x%i)) return false;
	}
	return true;
}

int main(){
	int n;cin>>n;
	if(ok(n)){
		puts("yes");
	}else puts("no");
	return 0;
}