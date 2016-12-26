/*
ID: ccodera1
LANG: C++
TASK: numtri
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int g[1010][1010];

void init(){
	memset(g,0,sizeof(g));
}

int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	init();
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>g[i][j];
		}
	}

	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			g[i][j]=max(g[i-1][j]+g[i][j],g[i-1][j-1]+g[i][j]);
		}
	}
	int maxn=-1000;
	for(int i=1;i<=n;i++){
		maxn=max(g[n][i],maxn);
	}
	cout<<maxn<<endl;
	return 0;
}