#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int f[55][55][55][55];
int g[55][55];

int main(){
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	int M,N;
	cin>>M>>N;
	for(int i=1;i<=M;++i){
		for(int j=1;j<=N;++j){
			cin>>g[i][j];
		}
	}
	int sum;
	for(int i=1;i<=M;++i){
		for(int j=1;j<=N;++j){
			for(int k=1;k<=M;++k){
				for(int l=1;l<=N;++l){
					sum=g[i][j]+max(max(f[i-1][j][k-1][l],f[i][j-1][k][l-1]),max(f[i][j-1][k-1][l],f[i-1][j][k][l-1]));
					if(i==k && j==l){
						f[i][j][k][l]+=sum;
					}else{
						f[i][j][k][l]+=sum+g[k][l];
					}
				}
			}
		}
	}
	cout<<f[M][N][M][N];
	fclose(stdin);
	fclose(stdout);
	return 0;
}