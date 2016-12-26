#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

map<int,int> M;
map<int,bool> idx;

int a[200100];
bool cmp(int a,int b){
	return a<b;
}


int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
		M[a[i]]+=1;
	}
	sort(a,a+N,cmp);
	for(int i=0;i<N;++i){
		if(!idx[a[i]]){
			printf("%d %d\n",a[i],M[a[i]]);
			idx[a[i]]=true;
		}
	}
	return 0;
}