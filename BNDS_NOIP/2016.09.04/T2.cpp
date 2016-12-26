#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10001];
int N;

void f(int t,int k){
	if(t==N){
		for(int i=1;i<k;++i){
			printf("%d-",a[i]);
		}
		cout<<N<<"\n";
	}else{
		if(t>N) return;
		a[k]=t;
		f(t+2,k+1);
		f(t+1,k+1);
	}
}

int main(){
	cin>>N;
	f(0,1);
	return 0;
}