#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[40][40][40][40];
int n1,n2,n3,n4;
int map[1000];

int N,M;
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>map[i];
	}
	n1=n2=n3=n4=0;
	for(int i=0;i<M;i++){
		int cd;cin>>cd;
		switch(cd){
			case 1:++n1;break;
			case 2:++n2;break;
			case 3:++n3;break;
			case 4:++n4;break;
		}
	}
	dp[0][0][0][0]=map[0];
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			for(int k=0;k<=n3;k++){
				for(int l=0;l<=n4;l++){
					if(i>0){
						dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+map[i+j*2+k*3+l*4]);
					}
					if(j>0){
						dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+map[i+j*2+k*3+l*4]);
					}
					if(k>0){
						dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+map[i+j*2+k*3+l*4]);
					}
					if(l>0){
						dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+map[i+j*2+k*3+l*4]);
					}
				}
			}
		}
	}
	cout<<dp[n1][n2][n3][n4];
	return 0;
}