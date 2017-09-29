#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

#define rint register int

ll f[100100],g[100100],h[100100];

map<int,int> idx;

int N,M;

int main(){
	ios::sync_with_stdio(false);
	cin>>N;
	for(rint i = 1;i<=N;++i){
		cin>>f[i];
		if(!idx[f[i]]){
			idx[f[i]] = ++M;
			h[M] = f[i];
		}
		g[i] = idx[f[i]];
	}
	for(int i=1;i<=M;++i){
		if(g[h[i]] != i){
			puts("-1");return 0;
		}
	}
	cout<<M<<endl;
	for(int i=1;i<=N;++i) cout<<g[i]<<' ';
	puts("");
	for(int i=1;i<=M;++i) cout<<h[i]<<' ';
	return 0;
}