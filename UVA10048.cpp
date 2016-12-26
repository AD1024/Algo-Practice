#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int VCNT = 110;
const int INF = 0xffffff;
const int TAG = -10000;

int C,S,Q;
int g[VCNT][VCNT];

inline void init(){
	for(int i=1;i<=C;i++){
		for(int j=1;j<=C;j++){
			if(i!=j)
				g[i][j]=g[j][i]=TAG;
			else
				g[i][j]=0;
		}
	}
}

int CASE=1;

inline int max2(int &a,int &b){
	return a>b?a:b;
}

int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%d%d%d",&C,&S,&Q) && (C || S || Q)){
		init();
		if(CASE>1) cout<<'\n';
		for(int i=1;i<=S;i++){
			int c1,c2,d;
			scanf("%d%d%d",&c1,&c2,&d);
			g[c1][c2]=g[c2][c1]=d;
		}
		for(int k=1;k<=C;++k)
			for(int i=1;i<=C;++i)
				for(int j=1;j<=C;++j){
					if(g[i][k]!=TAG && g[k][j]!=TAG){
						if(g[i][j]==TAG || g[i][j]>max2(g[i][k],g[k][j])){
							g[i][j]=max2(g[i][k],g[k][j]);
						}
					}
				}
		printf("Case #%d\n",CASE++);
		for(int i=1;i<=Q;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			if(g[u][v]==TAG)
				printf("no path\n");
			else
				printf("%d\n",g[u][v]);
		}
	}
	return 0;
}