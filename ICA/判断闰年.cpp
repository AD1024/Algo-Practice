#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int N;

int main(){
	cin>>N;
	if(N%400==0){
		puts("Y");
	}else if(N%100!=0 && N%4==0){
		puts("Y");
	}else puts("N");
	return 0;
}