#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int dx[]={0,0,1,-1,1,1,-1,-1};
const int dy[]={1,-1,0,0,1,-1,1,-1};

struct Pos{
	int x,y;
	Pos(){}
	Pos(int xx,int yy){
		x = xx;
		y = yy;
	}
};

bool vis[60][60];

queue<Pos> q;

inline void enqueue(Pos p){
	if(!vis[p.x][p.y]){
		q.push(p);
	}
}

inline bool validate(int x,int y){
	if(x >= N or y >= N or x < 0 or x < 0 or y < 0 ) return false; // 在图里？
	if(vis[x][y]) return false;// 访问过？
	if(g[x][y] != 0) return false;//有雷？
	return true;
}

void bfs(Pos start){
	enqueue(start);
	Pos k;
	while(!q.empty()){
		k = q.front();
		q.pop();int nx,ny;
		work(k); // 处理这个点的信息
		for(int i=0;i<8;++i){
			nx = k.x+dx[i];
			ny = k.y+dy[i];
			if(validate(nx,ny)){
				enqueue(Pos(nx,ny));
			}
		}
	}
}