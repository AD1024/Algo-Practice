#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10010];
int t[10010];

void mergesort(int l,int r){
	if(r-l<=0) return;
	int mid = (l+r)>>1;
	int p1 = l;
	int p2 = mid+1;
	int i=l;
	mergesort(l,mid);
	mergesort(mid+1,r);
	while(p1<=mid || p2<=r){
		if(p2>r || (p1<=mid && a[p1]<=a[p2])){
			t[i++] = a[p1++];
		}else{
			t[i++] = a[p2++];
		}
	}
	for(i=l;i<=r;++i){
		a[i] = t[i];
	}
}

int main(){
	int N;cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	mergesort(1,N);
	for(int i=1;i<=N;++i){
		cout<<a[i]<<" ";
	}
	return 0;
}