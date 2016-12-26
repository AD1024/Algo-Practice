#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

int g[210][210];

int N;int M;int K;

inline int read(){
	int a=0;
	char ch = getchar();
	while(ch>'9' || ch<'0'){
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		a = a * 10+ch-'0';
		ch=getchar();
	}
	return a;
}

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
bool vis[220][220];

struct Pos{
	int x,y;
	int H;
	Pos(){}
	Pos(int xx,int yy){
		x=xx;y=yy;
	}
	void init(){
		x=read();y=read();
		H=g[x][y];
	}
};
Pos list[100100];
int tx,ty;bool flag=false;

void bfs(){
	queue<Pos> q;
	for(int i=1;i<=K;++i){
		q.push(list[i]);
	}
	Pos k;int cx,cy;
	while(!q.empty()){
		k=q.front();q.pop();
		if(vis[k.x][k.y]) continue;
		vis[k.x][k.y]=true;
		if(k.x==tx && k.y==ty){
			puts("YES");
			flag = true;
			return;
		}
		for(int i=0;i<4;++i){
			cx=k.x+dx[i];
			cy=k.y+dy[i];
			if(cx>=1 && cx<=N && cy>=1 && cy<=M && g[cx][cy]<=k.H){
				q.push(Pos(cx,cy));
			}
		}
	}
}

int main(){
	int T;T=read();
	while(T--){
		memset(vis,false,sizeof(vis));
		flag=false;

		N=read();M=read();
		for(register int i=1;i<=N;++i){
			for(register int j=1;j<=N;++j){
				g[i][j]=read();
			}
		}
		tx=read();ty=read();
		K=read();
		for(int i=1;i<=K;++i){
			list[i].init();
		}
		bfs();
		if(!flag){
			puts("NO");
		}
	}
	return 0;
}