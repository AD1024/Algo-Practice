#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[51][51][51][51];
int g[51][51];
int M,N;
int main(){
	cin>>M>>N;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=M;k++){
				for(int l=1;l<=N;l++){
					int sum=max(max(f[i-1][j][k-1][l],f[i][j-1][k][l-1]),max(f[i-1][j][k][l-1],f[i][j-1][k-1][l]));
					if(i==k && j==l){
						f[i][j][k][l]=sum+g[i][j];
					}else{
						f[i][j][k][l]=sum+g[i][j]+g[k][l];
					}
				}
			}
		}
	}
	cout<<f[M][N][M][N];
	return 0;
}