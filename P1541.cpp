#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define CARD 41
#define MAXN 361
int f[CARD][CARD][CARD][CARD];
int g[MAXN];

int main(){
	int N,M;
	cin>>N>>M;
	int c1,c2,c3,c4;
	c1=c2=c3=c4=0;
	for(int i=0;i<N;i++){
		cin>>g[i];
	}
	for(int i=1;i<=M;i++){
		int tp;cin>>tp;
		switch(tp){
			case 1:++c1;break;
			case 2:++c2;break;
			case 3:++c3;break;
			case 4:++c4;break;
		}
	}
	f[0][0][0][0]=g[0];
	for(int i=0;i<=c1;i++){
		for(int j=0;j<=c2;j++){
			for(int k=0;k<=c3;k++){
				for(int l=0;l<=c4;l++){
					if(i>0)
						f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+g[i+j*2+k*3+l*4]);
					if(j>0)
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+g[i+j*2+k*3+l*4]);
					if(k>0)
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+g[i+j*2+k*3+l*4]);
					if(l>0)
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+g[i+j*2+k*3+l*4]);
				}
			}
		}
	}
	cout<<f[c1][c2][c3][c4];
	return 0;
}