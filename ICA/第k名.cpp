#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct P{
	string id;
	double x;
};

P a[100100];
bool cmp(P a,P b){
	return a.x>b.x;
}
int N,K;
int main(){
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		cin>>a[i].id>>a[i].x;
	}
	sort(a+1,a+1+N,cmp);
	cout<<a[K].id<<" "<<a[K].x;
	return 0;
}