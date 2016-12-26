#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

inline bool ok(int x){
	if(x%7==0) return true;
	while(x){
		int c = x%10;
		if(c==7) return true;
		x/=10;
	}
	return false;
}

int N;

int main(){
	long long ans=0;
	cin>>N;
	for(int i=1;i<=N;++i){
		if(!ok(i)){
			ans+=i*i;
		}
	}
	cout<<ans;
	return 0;
}