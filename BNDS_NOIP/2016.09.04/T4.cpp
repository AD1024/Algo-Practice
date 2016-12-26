#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N;

int a[10];

void f(int idx){
	if(idx>N){
		for(int i=1;i<=N;++i){
			cout<<a[i];
		}
		puts("");
	}else{
		for(int i=1;i<=N;++i){
			a[idx]=i;
			f(idx+1);
		}
	}
}

int main(){
	cin>>N;
	f(1);
	return 0;
}