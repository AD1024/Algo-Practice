#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	int N;
	cin>>N;
	if(N>=90 && N<=100){
		puts("A");
	}else if(N>=80 && N<=89){
		puts("B");
	}else if(N>=60 && N<=79){
		puts("C");
	}else{
		puts("D");
	}
	return 0;
}