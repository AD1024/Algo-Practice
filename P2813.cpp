#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100001],b[100001];
int N,M;
bool idx[100001];
int main(){
	memset(idx,true,sizeof(idx));
	cin>>M>>N;
	for(int i=1;i<=M;++i){
		cin>>b[i];
	}
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+N);
	int cur=1;
	for(int i=1;i<=N;++i){
		if(cur>M) break;
		if(a[i]>b[cur] && idx[i]){
			idx[i]=false;
			++cur;
		}
	}
	int ans=0;
	for(int i=1;i<=N;++i){
		if(idx[i]){
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}