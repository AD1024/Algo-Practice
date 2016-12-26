#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int g[3010][3010];
int dp[3010][3010];

int M,N;
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;++i){
		for(int j=1;j<=N;++j){
			scanf("%d",&g[i][j]);
			if(g[i][j]==1){
				dp[i][j]=1;
			}
		}
	}
	for(int i=1;i<=M;++i){
		for(int j=2;j<=N;++j){
			if(g[i][j]==0) continue;
			if(g[i][j-1]!=0) g[i][j]+=g[i][j-1];
			if(g[])
		}
	}
}