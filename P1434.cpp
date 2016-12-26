#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int g[101][101];
bool vis[101][101];
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main(){
	int R,C;
	scanf("%d%d",&R,&C);
	int dp[101][101];
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin>>g[i][j];
			dp[i][j]=1;
		}
	}
	bool flag=true;
	int dx,dy;
	int ans=-1000;
	while(flag){
		flag=false;
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				ans=max(ans,dp[i][j]);
				for(int k=0;k<4;k++){
					dx=i+dir[k][0];
					dy=j+dir[k][1];
					if(dx>=1 && dy>=1 && dx<=R && dy<=C && g[dx][dy]>g[i][j] && dp[dx][dy]<dp[i][j]+1){
						flag=true;
						dp[dx][dy]=dp[i][j]+1;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}