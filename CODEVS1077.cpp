#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int g[110][110];

int main(){
	int N;
	int query;
	cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>g[i][j];
		}
	}

	for(int k=1;k<=N;++k){
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(g[i][k]+g[k][j]<g[i][j]){
					g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
	cin>>query;
	while(query--){
		int f,t;
		cin>>f>>t;
		cout<<g[f][t]<<"\n";
	}
	return 0;
}
