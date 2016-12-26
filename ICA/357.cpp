#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ps(x) putchar(x)

int main(){
	int N;
	while(cin>>N){
		if(N%3==0){
			ps('3');ps(' ');
		}
		if(N%5==0){
			ps('5');
			ps(' ');
		}
		if(N%7==0){
			ps('7');ps(' ');
		}
		if(N%7 && N%3 && N%5){
			ps('n');
		}
		ps('\n');
	}
	return 0;
}