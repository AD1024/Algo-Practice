#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int M,N;
	cin>>N>>M;
	int cnt=0;
	for(int i=1;i<=N;++i){
		int k=i;
		while(k){
			if(k%10==M){
				cnt++;
			}
			k/=10;
		}
	}
	cout<<cnt;
	return 0;
}