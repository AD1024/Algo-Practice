#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 40;
int f[MAXN][MAXN];

int main(){
	memset(f,0,sizeof(f));
	int m,n;
	cin>>n>>m;
	f[1][0]=1;
	for(int j=1;j<=m;j++){
		for(int i=2;i<=n-1;i++){
			f[i][j]=f[i-1][j-1]+f[i+1][j-1];
			f[1][j]=f[2][j-1]+f[n][j-1];
			f[n][j]=f[n-1][j-1]+f[1][j-1];
		}
	}
	cout<<f[1][m];
	return 0;
}