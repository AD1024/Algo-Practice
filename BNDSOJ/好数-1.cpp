#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[50][10][50][50];

int k[101000];

int dfs(int idx,int p,int q,int r){
	if(!idx) return int(r!=0);
	if(dp[idx][p][q][r]>=0) return dp[idx][p][q][r];
	else{
		int i;
		if(q){
			i = a[idx];
		}else{
			i = 1;
		}
		int md,zz;int tot = 0;
		for(int j=0;j<=i;++j){
			if(j==1 && p==3) continue;
			if(!j && !p && !r) continue;
			if(j==i){
				md=1;
			}else{
				md=0;
			}
			if(!j && !r){
				zz=1;
			}else{
				zz=0;
			}
			tot += dfs(idx-1,((s&1)<<1)+j,md,zz);
		}
		return f[idx][p][q][r]=tot;
	}
}

int getLen(int x){
	int ret = 0;
	while(x){
		ret++;
		x>>=1;
	}
	return ret;
}

int main(){
	long long l,r;
	memset(dp,-1,sizeof(dp));
	cin>>l>>r;
	dfs(getLen(r),0,0,0);
	dfs(getLen(l),0,0,0);
	getLen(r);
	
	return 0;
}