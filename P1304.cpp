#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

inline bool isprime(int x){
	if(x==2) return true;
	if(x==1) return false;
	if(!(x&1)) return false;
	for(int i=2;i<=sqrt(x);++i){
		if(!(x%i)) return false;
	}
	return true;
}
int N;
int main(){
	cin>>N;
	for(int i=4;i<=N;i+=2){
		for(int j=2;j<=i/2;++j){
			if(isprime(j) && isprime(i-j)){
				printf("%d=%d+%d\n",i,j,i-j);
				break;
			}
		}
	}
	return 0;
}