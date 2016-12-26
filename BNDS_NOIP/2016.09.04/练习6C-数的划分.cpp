#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N,K;
int ans=0;
void f(int idx,int r,int last){
	if(idx>K){
		if(r==0)
			ans++;
	}else{
		for(int i=last;i<=N;++i){
			f(idx+1,r-i,i);
		}
	}
}

int main(){
	cin>>N>>K;
	f(1,N,1);
	cout<<ans;
	return 0;
}