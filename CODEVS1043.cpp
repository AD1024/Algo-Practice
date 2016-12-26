#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int gSize=20;

int g[gSize][gSize];
int N;
int f[gSize][gSize][gSize][gSize];

inline int MAX(int x,int y){
	return x>y?x:y;
}


int main(){
	cin>>N;
	int x,y,v;
	while(cin>>x>>y>>v){
		if(x==0 && y==0 && v==0) break;
		g[x][y]=v;
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			for(int k=1;k<=N;++k){
				for(int l=1;l<=N;++l){
					int sum=g[i][j]+MAX(MAX(f[i-1][j][k-1][l],f[i][j-1][k][l-1]),MAX(f[i][j-1][k-1][l],f[i-1][j][k][l-1]));
					if(i==k && j==l){
						f[i][j][k][l]+=sum;
					}else{
						f[i][j][k][l]+=sum+g[k][l];
					}
				}
			}
		}
	}
	cout<<f[N][N][N][N];
	return 0;
}
