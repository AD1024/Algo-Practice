#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAXN 110
#define ABS(x) x>0?x:-x
int fa[MAXN];
struct Pool{
	int h;
	int id;
	Pool(){}
	Pool(int hx,int idx){
		h=hx;
		id=idx;
	}
};

Pool g[MAXN][MAXN];
int PID = 1;
int N;
int ans=0;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
inline int Find(int x){
	while(x!=fa[x]) x=fa[x];
	return x;
}

inline void Union(int x,int y){
	int fx=Find(x);
	int fy=Find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}

inline void Search(int x,int y){
	int xx,yy;
	int MIN=0x3f3f;
	int sx=-1,sy=-1;
	for(int i=0;i<4;++i){
		xx=x+dx[i];yy=y+dy[i];
		if(xx>N || xx<1 || yy>N || yy<1) continue;
		if(ABS(g[xx][yy].h-g[x][y].h)<MIN && Find(g[xx][yy].id)!=Find(g[x][y].id)){
			MIN=ABS(g[xx][yy].h-g[x][y].h);
			sx=xx;sy=yy;
		}
	}
	if(sx!=-1 && sy!=-1){
		ans+=MIN;
		Union(g[sx][sy].id,g[x][y].id);
	}
}

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		fa[i]=i;
		for(int j=1;j<=N;++j){
			int h;cin>>h;
			g[i][j]=Pool(h,PID++);
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			Search(i,j);
		}
	}
	cout<<ans;
	return 0;
}