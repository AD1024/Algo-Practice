#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long X;

long long F(long long x){
	if(x>=101) return x-10;
	else return F(F(x+11));
}

int main(){
	while(cin>>X && X){
		cout<<F(X)<<endl;
	}
	return 0;
}