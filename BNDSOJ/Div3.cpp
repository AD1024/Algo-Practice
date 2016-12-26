#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int f(int idx){
	int a=idx/3;
	int b=idx%3;
	if(b){
		return b-1+a*2;
	}else return a*2;
}

int main(){
	int N;
	cin>>N;
	cout<<f(N);
	return 0;
}