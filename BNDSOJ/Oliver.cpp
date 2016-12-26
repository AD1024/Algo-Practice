#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;

struct Pos{
	int x,y;
	int step;
	Pos(){}
	Pos(int xx,int yy,int ss){
		x=xx;y=yy;step=ss;
	}
};

queue<Pos> q;
int g[44][44];
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
bool vis[44][44];int N;

inline void BFS(){
	q.push(Pos(N,N,1));
	vis[N][N]=1;
	Pos k;int px,py;int cx,cy;
	while(q.size()){
		k=q.front();q.pop();
		px=k.x;py=k.y;
		if(px==1 && py==1){
			printf("%d\n",k.step);
			return;
		}
		for(int i=0;i<4;++i){
			cx=px+dx[i];
			cy=py+dy[i];
			if(!vis[cx][cy] && cx<=N && cx>=1 && cy<=N && cy>=1 && !g[cx][cy]){
				vis[cx][cy]=1;
				q.push(Pos(cx,cy,k.step+1));
			}
		}
	}
}

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>g[i][j];
		}
	}
	BFS();
	return 0;
}