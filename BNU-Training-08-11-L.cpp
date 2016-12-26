#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	long long ans,n;
	double r;
	long long t;
	cin>>n;
	r=n;
	long long tmp=n;
	if(n==0){
		puts("1");
		exit(0);
	}
	ans=0;
	long long k;
	for(long long i=1;i<=n;++i){
		double p=i;
		k=(long long)sqrt(r*r-p*p);
		if(tmp==k){
			ans++;
		}else{
			ans+=tmp-k;
		}
		tmp=k;
	}
	cout<<(ans*4)<<"\n";
	return 0;
}