#include <iostream>
#include <cstdio>
using namespace std;


typedef long long ll;

ll f[101000];

inline void init(){
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=50;++i){
		f[i] = f[i-1] * i;
	}
}

inline ll C(int n,int m){
	return f[n]/(f[m]*f[n-m]);
}

int main(){
	
}