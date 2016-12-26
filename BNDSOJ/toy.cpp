#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct P{
	char name[50];
	int f;
};
P idx[100100];
int N;int M;
int ans=1;
int main(){
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>idx[i].f>>idx[i].name;
	}
	int op,k;
	while(M--){
		cin>>op>>k;
		if(op){ // right
			if(idx[ans].f){ // Out
				ans = (ans+N-k%N)%N;
			}else{ // in
				ans = (ans+k)%N;
			}
		}else{ // left
			if(idx[ans].f){ // out
				ans = (ans+k)%N;
			}else{ // in
				ans = (ans+N-k%N)%N;
			}
		}
		if(!ans) ans=N;
	}
	puts(idx[ans].name);
}