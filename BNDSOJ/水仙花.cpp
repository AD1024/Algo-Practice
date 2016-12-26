#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int x;
	cin>>x;
	int k=x;
	int sum=0;
	while(x){
		int b=x%10;
		x/=10;
		sum+=b*b*b;
	}
	if(k==sum){
		puts("yes");
	}else{
		puts("no");
	}
	return 0;
}