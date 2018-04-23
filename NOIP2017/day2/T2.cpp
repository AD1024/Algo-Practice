#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
int n,m;
ll len[12][1<<12];
ll edge[12][12],B[1<<12][1<<12];
int A[1<<12][1<<12],cnt[1<<12];
ll dp[12][1<<12];

inline ll calc(int state1,int state2){
	ll res=0;
	for (int i=0;i<n;i++){
		if (state2 & (1<<i)) {
			res+=len[i][state1]; // state2转移到state1的最小代价
		}
	}
	res=min(res,ll(1e8));
	return res;
}
inline void init(){
	for (int i=0;i<n;i++){
		for (int j=1;j<(1<<n);j++){
			if (!(j & (1 << i))){
				len[i][j] = 1e8; // i与集合j中点的最短边
				for (int k=0;k<n;k++) {
					if (j&(1<<k)) {
						len[i][j] = min(len[i][j], edge[i][k]);
					}
				}
			}
		}
	}
	for (int i=1;i<(1<<n);i++){
		cnt[i]=0;
		for (int j=1;j<(1<<n);j++){
			if (!(i & j)) {
				A[i][cnt[i]]=j;
				B[i][cnt[i]++]=calc(i,j);
			}
		}
	}
}
ll dfs(int dep,int state){
	if (state==(1<<n)-1) return 0;
	if (dp[dep][state] != -1) return dp[dep][state];
	ll res = 1e8;
	for (int i=0;i<cnt[state];i++) {
		res = min(res, B[state][i] * dep + dfs(dep + 1, state | A[state][i]));
	}
	return dp[dep][state]=res;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(edge, 0x3f3f, sizeof(edge));
	int u,v,t;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u, &v, &t);
		u--;v--;
		edge[u][v]=min(edge[u][v],(ll)t),edge[v][u]=edge[u][v];
	}
	init();
	memset(dp, -1, sizeof(dp));
	ll res=1e8;
	for (int i=0;i<n;i++) {
		res = min(res, dfs(1, 1<<i));
	}
	printf("%lld\n", res);
	return 0;
}
