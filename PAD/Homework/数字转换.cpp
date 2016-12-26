#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define to(x) x-'0'

const string list[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
	string a;
	cin>>a;
	for(int i=0;i<a.size();++i){
		cout<<list[to(a[i])]<<" ";
	}
	return 0;
}