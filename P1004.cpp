#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 20;

int f[MAXN][MAXN][MAXN][MAXN];

int g[MAXN][MAXN];

int main(){
	int n;
	cin>>n;
	int a,b,v;
	while(cin>>a>>b>>v&&a&&b){
		g[a][b]=v;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i][j-1][k][l-1]),max(f[i][j-1][k-1][l],f[i-1][j][k][l-1]))+g[i][j]+g[k][l];
					if(i==k || j==l){
						f[i][j][k][l]-=g[i][j];
					}
				}
			}
		}
	}
	cout<<g[n][n]+max(f[n-1][n][n][n-1],f[n][n-1][n-1][n]);
	return 0;
}