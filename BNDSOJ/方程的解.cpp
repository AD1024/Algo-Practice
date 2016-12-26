#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
int a,b,c,d;

int main(){
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	if(a==0){
		puts("one answer");
	}else if(d==0){
		puts("two equal answers");
	}else if(d>0){
		puts("two answers");
	}else if(d<0){
		puts("no answer");
	}
	return 0;
}