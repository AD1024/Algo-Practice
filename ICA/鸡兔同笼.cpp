#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int a;
int main(){
	cin>>a;
	int maxn,minm;
	if(a%2!=0){
		cout<<0<<" "<<0;
		return 0;
	}
	if(a%4==0){
		minm = a/4;
	}else{
		int pa=a;
		while(pa%4){
			pa--;
		}
		minm=pa/4+(a-pa)/2;
	}
	maxn=a/2;
	cout<<minm<<" "<<maxn;
	return 0;
}