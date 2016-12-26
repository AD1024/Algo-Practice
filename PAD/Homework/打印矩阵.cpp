#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int N;
	cin>>N;
	int k=1;
	bool rev=false;
	while(k<=N*N){
		if(rev){
			rev=false;
			for(int i=k+N-1;i>=k;--i){
				cout<<i<<" ";
			}
			puts("");
		}else{
			rev=true;
			for(int i=k;i<=k+N-1;++i){
				cout<<i<<" ";
			}
			puts("");
		}
		k+=N;
	}
	return 0;
}