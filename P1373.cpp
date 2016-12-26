#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MOD 1000000007
int M,N;
const int MAXN = 880;

int f[MAXN][MAXN][16][2];
int g[MAXN][MAXN];
int K;

int ans=0;
int k=0;

inline void print(){
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			ans=(ans+f[i][j][0][1])%MOD;
		}
	}
	cout<<ans;
}

inline void DP(){
	++K;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			f[i][j][g[i][j]][0]=1;
			for(int k=0;k<K;++k){
				int &tx=f[i][j][k][0];
				int &ty=f[i][j][k][1];
				tx+=f[i-1][j][(k-g[i][j]+K)%K][1]+f[i][j-1][(k-g[i][j]+K)%K][1];
				ty+=f[i-1][j][(k+g[i][j])%K][0]+f[i][j-1][(k+g[i][j])%K][0];
				tx%=MOD;
				ty%=MOD;
			}
		}
	}
}


inline void init(){
	cin>>N>>M>>K;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			cin>>g[i][j];
		}
	}
}

int main(){
	init();
	DP();
	print();
	return 0;
}