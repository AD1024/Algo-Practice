#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 200;

bool vis[MAXN];
bool map[MAXN][MAXN];
int ans[MAXN];
int M,N;
bool flag=0;
inline void init(){
	int F,T;
	memset(vis,false,sizeof(vis));
	memset(map,false,sizeof(map));
	flag=false;
	for(int i=1;i<=M;++i){
		scanf("%d%d",&F,&T);
		map[F][T]=map[T][F]=true;
	}
	vis[1]=true;
}

void dfs(int u,int v,int idx){
	ans[idx]=v;
	if(idx==N && map[v][1]){
		flag=true;
		return;
	}
	int y;
	for(int i=1;i<=N;++i){
		if(map[v][i] && !vis[i]){
			vis[i]=true;
			dfs(u,i,idx+1);
			vis[i]=false;
		}
		if(flag) return;
	}
}

int main(){
	while(scanf("%d%d",&N,&M)!=EOF){
		init();
		dfs(1,1,1);
		if(flag){
			for(int i=1;i<N;++i){
				cout<<ans[i]<<" ";
			}
			cout<<ans[N];puts("");
		}else{
			puts("no solution");
		}
	}
}