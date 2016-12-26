#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 10001;

#define REP(i,f,t) for(int i=f;i<=t;++i)
#define INF 0x3f3f3f3f
#define pb push_back

vector<int> g[MAXN];
vector<int> f[MAXN];
double dp[MAXN][MAXN];
double p[MAXN],dist[MAXN];
int M,N;

inline void init(){
	memset(dp,0,sizeof(dp));
}

inline int MAX(int x,int y){
	return x>y?x:y;
}

inline double getNext(int pos,int d){
	double ans=0.0;
	memset(p,0,sizeof(p));
	REP(i,1,N){
		if(dp[pos][i]==d){
			REP(j,0,g[i].size()-1){
				p[g[i][j]]+=(double)1/N/g[i].size();
			}
		}
	}
	f.clear();
	REP(i,1,N){
		if(p[i]>-INF){
			f.pb(i);
		}
	}
	double t;
	REP(i,1,N){
		REP(j,0,f.size()-1){
			dist[dp[i][f[j]]]=MAX(dist[dp[i][f[j]]],p[f[j]]);
		}
		REP(j,0,f.size()-1){
			t+=dist[dp[i][f[j]]];
			dist[dp[i][f[j]]]=0;
		}
		ans=MAX(ans,t);
	}
	return ans;
}

inline void Floyd(){
	REP(k,1,N){
		REP(i,1,N){
			REP(j,1,N){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}

inline void work(){
	scanf("%d%d",&N,&M);
	REP(i,1,N){
		REP(j,1,N){
			if(i!=j){
				dp[i][j]=N+1;
			}
		}
	}
	int u,v;
	REP(i,1,M){
		scanf("%d%d",&u,&v);
		dp[u][v]=dp[v][u]=1;
		g[u].pb(v);
		g[v].pb(u);
	}
	Floyd();
	double t,ans;
	double c1,c2;
	REP(i,1,N){
		t=0.0;
		REP(j,0,N-1){
			int tot=0;
			REP(k,1,N){
				if(dp[i][k])
					tot+=1;
			}
			if(!tot) continue;
			c1=(double)1/N;
			c2=getNext(i,j);
			t+=max(c1,c2);
		}
		ans=max(ans,t);
	}
	printf("%.12f\n",ans);
}

int main(){
	init();
	work();
	return 0;
}