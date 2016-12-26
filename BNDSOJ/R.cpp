#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	int N;
	cin>>N;
	if(N%400==0 || (N%100!=0 && N%4==0)){
		puts("leap year");
	}else{
		puts("normal year");
	}
	return 0;
}