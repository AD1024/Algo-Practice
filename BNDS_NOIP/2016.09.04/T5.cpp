#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool used[10];
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
			if(!used[i]){
				used[i]=1;
				a[idx]=i;
				f(idx+1);
				used[i]=false;
			}
		}
	}
}

int main(){
	cin>>N;
	f(1);
	return 0;
}
