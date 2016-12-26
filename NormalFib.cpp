#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
#define MOD 1000000007
ll fib[3]={1,1};

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	ll P;cin>>P;int pos=0;
	for(int i=2;i<=P;++i){
		pos=!pos;
		fib[pos]=(fib[pos]%MOD + fib[!pos]%MOD)%MOD;
	}
	cout<<fib[!pos];
	return 0;
}