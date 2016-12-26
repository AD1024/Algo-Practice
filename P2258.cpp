#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAXN 0x3f3f3f3f
int m,n;
int c,r;
int rr[20],cc[20][20];
int d[20][20];
int g[20][20];

inline int Abs(int x){
	return x>0?x:-x;
}
inline int MIN(int x,int y){
	return x>y?y:x;
}
int dp(int sel){
	int t[20];
	int cur=0;
	for(int i=0;i<n;++i){
		if((sel>>i) & 1){
			t[cur++]=i;
		}
	}
	for(int i=0;i<m;++i){
		rr[i]=0;
		for(int j=1;j<r;++j){
			rr[i]+=Abs(g[t[j]][i]-g[t[j-1]][i]);
		}

		for(int j=i+1;j<m;++j){
			cc[i][j]=0;
			for(int k=0;k<r;++k){
				cc[i][j]+=Abs(g[t[k]][i]-g[t[k]][j]);
			}
		}
	}
	memset(d,MAXN,sizeof(d));
	for(int i=0;i<m;++i){
		d[1][i]=rr[i];
	}
	for(int i=2;i<=c;++i){
		for(int j=i-1;j<m;++j){
			for(int k=0;k<j;++k){
				d[i][j]=MIN(d[i][j],d[i-1][k]+rr[j]+cc[k][j]);
			}
		}
	}
	int minm=MAXN;
	for(int i=0;i<m;++i){
		minm=MIN(minm,d[c][i]);
	}
	return minm;
}
int ans=MAXN;
void dfs(int idx,int sel,int row){
	if(idx>=n){
		if(row==0){
			ans=MIN(ans,dp(sel));
		}
	}else{
		if(row>0){
			dfs(idx+1,(sel<<1)|1,row-1);
		}
		if(row<=n-idx){
			dfs(idx+1, sel<<1, row);
		}
	}
}

inline void init(){
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&g[i][j]);
		}
	}
}

int main(){
	init();
	dfs(0,0,r);
	cout<<ans;
	return 0;
}