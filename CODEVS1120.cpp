#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int g[110][110];

//f[i,j]=max(f[i-1,j]+f[i,j],f[i-1,j+1]+f[i,j]);

int main(){
	int n;
	cin>>n;
	memset(g,-100,sizeof(g));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>g[i][j];
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			g[i][j]=max(g[i][j]+g[i-1][j-1],g[i][j]+g[i-1][j]);
		}
	}
	int maxn=-10000;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,g[n][i]);
	}
	cout<<maxn;
	return 0;
}
