#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n,k;

int f[5001][5001];

const long long MOD = 998244353;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;++i){
		f[1][i]=1;
	}
	for(int i=2;i<=k;++i){
		for(int j=0;j<=n-k;++j){
			if(i>j){
				f[i][j] = f[i-1][j];
			}else{
				f[i][j] = (f[i-1][j] + f[i][j-i]) % MOD;
			}
		}
	}
	printf("%d\n",f[k][n-k]);
	return 0;
}