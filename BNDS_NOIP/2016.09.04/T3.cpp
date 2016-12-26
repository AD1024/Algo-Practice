#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> g[10];
bool idx[10];
int ans=1;
int K,N;

void f(int t){
	if(idx[t]){
		return;
	}else{
		idx[t]=true;
		ans++;
		for(int i=0;i<g[t].size();++i){
			f(i);
		}
	}
}

int main(){
	cin>>N>>K;
	int u,v;
	for(int i=0;i<K;++i){
		cin>>u>>v;
		g[u].push_back(v);
	}
	f(N);
	cout<<ans;
	return 0;
}