#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
char g[200][200];
int ans[200][200];
int M,N;
const int dx[8]={1,0,-1,0,1,-1,1,-1};
const int dy[8]={0,1,0,-1,1,-1,-1,1};
const int w[8] ={1,1,1,1,2,2,2,2};

struct Point{
	int x,y,w;
	Point(void){}
	Point (int xx,int yy,int ww){
		x=xx;y=yy;w=ww;
	}
};
queue<Point> q;

inline void BFS(Point x){
	q.push(x);
	Point k;
	Point Next;
	int xx,yy;
	int nx,ny;
	while(q.size()){
		k=q.front();q.pop();
		xx=k.x;
		yy=k.y;
		for(int i=0;i<8;++i){
			nx=xx+dx[i];
			ny=yy+dy[i];
			if(!(nx<1 || nx>N || ny<1 || ny>M || k.w+w[i]>=ans[nx][ny])){
				Next.x=nx;
				Next.y=ny;
				Next.w=k.w+w[i];
				ans[nx][ny]=Next.w;
				q.push(Next);
			}
		}
	}
}

int main(){
    cin>>N>>M;
    memset(ans,INF,sizeof(ans));
    for(int i=1;i<=N;++i){
        scanf("%s",g[i]+1);
        for(int j=1;j<=M;++j){
        	if(g[i][j]=='1'){
        		ans[i][j]=0;
        	}
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(g[i][j]=='1'){
                BFS(Point(i,j,0));
            }
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cout<<ans[i][j]<<" ";
        }
        puts("");
    }
    return 0;
}