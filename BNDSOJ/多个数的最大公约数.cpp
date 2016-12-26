#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

inline int gcd(int x,int y){
	while(x^=y^=x^=y%=x);return y;
}

int main(){
	int N;
	cin>>N;
	int a[110];
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	int ans=gcd(a[1],a[2]);
	for(int i=3;i<=N;++i){
		ans=gcd(ans,a[i]);
	}
	cout<<ans;
	return 0;
}