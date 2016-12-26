#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

inline int sum(int x){
	int ret=0;
	while(x){
		ret+=x%10;
		x/=10;
	}
	return ret;
}

int main(){
	int N;
	cin>>N;
	long long ans=0;
	for(register int i=1;i<=N;++i){
		ans+=sum(i);
	}
	cout<<ans;
	return 0;
}