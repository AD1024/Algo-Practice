#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct P{
	int step=0;
	int x,y;
	int dir;
	P(){}
	P(int xx,int yy){x=xx;y=yy;}
};

char g[5][5];

const int N = 4;

const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,-1,-1,1,1};

inline bool judge(int x,int y){
	char k=g[x][y];
	P p=P(x,y);
	p.dir=-1;
	queue<P> q;
	q.push(p);
	vis[5][5];
	memset(vis,false,sizeof(vis));
	P t,xx,yy;
	while(q.size()){
		t=q.front();
		q.pop();
		vis[t.x][t.y]=true;
		xx=t.x;yy=t.y;
		for(int i=0;i<8;++i){
			if(t.dir==i || t.dir==-1){
				if(xx+dx[i]<=4 && xx+dx[i]>=1 && yy+dy[i]<=4 && yy+dy[i]>=1 && g[xx+dx[i]][yy+dy[i]]==k){
					P add=P(xx+dx[i],yy+dy[i]);
					add.step=t.step+1;
					add.dir=i;
					if(add.step==4) return true;
					q.push(add);
				}
			}
		}
	}
	return false;
}	

inline void work(P s){
	queue<P> q;
	
}

inline void init(){
	P start;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=1;++j){
			scanf("%c",g[i][j]);
			if(g[i][j]=='O'){
				start=P(i,j);
			}
		}
	}
}