#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Pack{
	double w;
	int v;
	void init(){
		cin>>w>>v;
	}
}p[1001000];

int N;

int main(){
	cin>>N;
	for(int i=1;i<=3;++i){
		p[i].init();
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=3;++i){
		int k = int(ceil(N/p[i].w));
		ans=min(ans,k*p[i].v);
	}
	cout<<ans;
}