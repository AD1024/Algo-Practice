#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int g[45][45];
int N;

struct pos{
	int x,y;
	pos(){}
	pos(int xx,int yy){
		x=xx;y=yy;
	}
}map[45*45];

int main(){
	cin>>N;
	g[1][N/2+1]=1; //初始化1的位置
	map[1]=pos(1,N/2+1); //记录1的位置
	for(int i=2;i<=N*N;++i){
		if(map[i-1].x==1 && map[i-1].y!=N){ //如果i-1在第一行不在最后一列
			g[N][map[i-1].y+1]=i;
			map[i]=pos(N,map[i-1].y+1);
		}else if(map[i-1].y==N && map[i-1].x!=1){ //如果i-1在最后一列不在第一行
			g[map[i-1].x-1][1]=i;
			map[i]=pos(map[i-1].x-1,1);
		}else if(map[i-1].x==1 && map[i-1].y==N){ //如果i-1在第一行最后一列
			g[map[i-1].x+1][map[i-1].y]=i;
			map[i]=pos(map[i-1].x+1,map[i-1].y);
		}else if(map[i-1].x!=1 && map[i-1].y!=N){ //如果既不在第一行也不在最后一列 
			if(g[map[i-1].x-1][map[i-1].y+1]==0){ //判断右上角
				g[map[i-1].x-1][map[i-1].y+1]=i;
				map[i]=pos(map[i-1].x-1,map[i-1].y+1);
			}else{
				g[map[i-1].x+1][map[i-1].y]=i;
				map[i]=pos(map[i-1].x+1,map[i-1].y);
			}
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<N;++j){
			printf("%d ",g[i][j]);
		}
		printf("%d\n",g[i][N]);
	}
	return 0;
}