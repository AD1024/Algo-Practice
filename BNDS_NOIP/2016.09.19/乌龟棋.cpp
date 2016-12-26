#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[44][44][44][44];
int M,N;
int a[1001];
int n1,n2,n3,n4;
int main(){
	freopen("tortoise.in","r",stdin);
	freopen("tortoise.out","w",stdout);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}

	for(int i=0;i<M;++i){
		int card;cin>>card;
		switch (card){
			case 1:n1++;break;
			case 2:n2++;break;
			case 3:n3++;break;
			case 4:n4++;break;
			default:break;
		}
	}
	f[0][0][0][0]=a[0];
	for(int i=0;i<=n1;++i){
		for(int j=0;j<=n2;++j){
			for(int k=0;k<=n3;++k){
				for(int l=0;l<=n4;++l){
					if(i>0)
						f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+a[i+j*2+k*3+l*4]);
					if(j>0)
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+a[i+j*2+k*3+l*4]);
					if(k>0)
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+a[i+j*2+k*3+l*4]);
					if(l>0)
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+a[i+j*2+k*3+l*4]);
				}
			}
		}
	}
	cout<<f[n1][n2][n3][n4];
	fclose(stdin);
	fclose(stdout);
	return 0;
}