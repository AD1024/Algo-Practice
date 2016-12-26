#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MOD 998244353

int n,k;
long long ans;

void f(int idx,int sum,int last){
	if(idx == k){
		if(sum == n){
			ans++;
			ans%=MOD;
		}
		return;
	}else{
		for(int i=last;i<=n;++i){
			f(idx+1,sum+i,i);
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	f(0,0,1);
	printf("%lld\n",ans);
	return 0;
}