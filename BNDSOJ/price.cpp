#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	int N;cin>>N;
	if(N<=3){
		puts("8.00");
	}else{
		double x=8.0;
		N-=3;
		x+=(double)N*1.6;
		printf("%.2f",x);
	}
	return 0;
}