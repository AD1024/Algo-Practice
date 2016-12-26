#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN=1001;
const int d[3][3]={{-1,0},{0,-1}};

int ans=0;

int m,n,k;
int feng[MAXN][MAXN];
int wifi[MAXN][MAXN];
int yz[MAXN][MAXN];

inline bool checkPos(int x,int y){
	return (x>=1 && x<=n && y>=1 && y<=m);
}

inline int getAns(int tot,int x,int y){
	tot+=(abs(yz[x][y]+x+y)^feng[x][y])*wifi[x][y];
	for(int i=0;i<2;i++){
		int dx=x+d[i][0];
		int dy=y+d[i][1];
		if(checkPos(dx,dy)){
			tot+=abs(yz[x][y]+yz[dx][dy]);		
		}
	}
	return tot;
}

inline void init(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&feng[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&wifi[i][j]);
		}
	}
}

void search(int x,int y,int sum){
	if(sum>ans) return;
	if(x==n && y==m){
		for(int i=-k;i<=k;i++){
			yz[x][y]=i;
			ans = min(getAns(sum,x,y),ans);
		}
		return;
	}
	for(int i=-k;i<=k;i++){
		yz[x][y]=i;
		if(y<m){
			search(x,y+1,getAns(sum,x,y));
		}else if(y==m){
			search(x+1,0,getAns(sum,x,y));
		}
	}
}

int main(){
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans+=((i+j)^feng[i][j])*wifi[i][j];
		}
	}
	search(1,1,0);
	cout<<ans<<"\n";
	return 0;
}
