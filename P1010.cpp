#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void solve(int x){
	bool plus=false;
	int a[100];
	int cur=0;
	while(x){
		a[cur++]=x%2;
		x/=2;
	}
	--cur;
	for(int i=cur;i>=0;i--){
		if(a[i]==0) continue;
		if(plus) printf("+");
		else plus=true;
		if(i==1) printf("2");
		if(i==0) printf("2(0)");
		if(i>1){
			printf("2(");
			solve(i);
			printf(")");
		}
	}
}


int main(){
	int N;
	cin>>N;
	solve(N);
	return 0;
}