#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
bool flag;
bool vis[61][61];
struct Pos{
	int x,y;
	int step;
	Pos(){}
	Pos(int xx,int yy,int s){
		x=xx;
		y=yy;
		step=s;
	}
};

int M,N;
const int dx[4]={2,2,1,1};
const int dy[4]={1,-1,2,-2};
queue<Pos> q;
inline void bfs(){
	q.push(Pos(1,1,0));
	Pos k;
	while(q.size()){
		k=q.front();q.pop();
		int x=k.x;
		int y=k.y;
		if(x==N && y==M){
			cout<<k.step;
			flag=true;
			return;
		}
		for(int i=0;i<4;++i){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx>=1 && xx<=N && yy>=1 && yy<=M && !vis[xx][yy]){
				vis[xx][yy]=true;
				Pos add=Pos(xx,yy,k.step+1);
				q.push(add);
			}
		}
	}
}

int main(){
	freopen("knight.in","r",stdin);
	freopen("knight.out","w",stdout);
	cin>>N>>M;
	bfs();
	if(!flag){
		puts("No solution!");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}