#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N;
int a[1001];

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	for(int i=N;i>=1;--i){
		cout<<a[i]<<" ";
	}
	return 0;
}