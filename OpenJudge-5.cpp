#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M;
int a[10001];
int b[10001];

inline void read(){
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	for(int i=1;i<=M;++i){
		cin>>b[i];
	}
}

inline void Sort(){
	sort(a+1,a+1+N);
	sort(b+1,b+1+M);
}

inline void  print(){
	for(int i=1;i<=N;++i){
		cout<<a[i]<<" ";
	}
	//puts("");
	for(int i=1;i<=M;++i){
		cout<<b[i]<<" ";
	}
}

int main(){
	read();
	Sort();
	print();
	return 0;
}