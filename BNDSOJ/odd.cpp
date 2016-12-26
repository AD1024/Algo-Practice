#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(){
	int N;
	cin>>N;
	if(!(N&1)){
		puts("even number");
	}else{
		puts("odd number");
	}
	return 0;
}