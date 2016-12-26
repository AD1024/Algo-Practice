#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int M,N,K,Q;
#define MOD 1000000007
inline long long fac(int x){
	long long ret=1;
	for(int i=2;i<=x;++i){
		ret*=i;
	}
	return ret;
}

inline long long C(int x,int y){
	return fac(x)/fac(x-y)*fac(y);
}

int main(){
	cin>>Q;
	while(Q--){
		cin>>M>>N>>K;
		printf("%lld\n", C(N-M*K-1,M-1)*N%MOD*(ll)pow(M,MOD-2)%MOD);
	}
	return 0;
}