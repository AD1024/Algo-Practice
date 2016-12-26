#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int N,K;

int main(){
	cin>>N>>K;
	long long sum=0;
	if(N>K){
		for(int i=1;i<=K;++i){
			sum+=K%i;
		}
		sum+=K*(N-K);
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=N;++i){
		sum+=K%i;
	}
	cout<<sum;
	return 0;
}