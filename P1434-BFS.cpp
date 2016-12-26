#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct P{
	int x,y;
};

const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};

int g[101][101];

int R,C;

int ans[10001];
int vis[1001][1001];
int cur=1;
queue<P> q;
int bfs(P pt){
	vis[pt.x][pt.y]=cur;
	q.push(pt);
	int cnt=0;
	while(!q.empty()){
		P t=q.front();
		q.pop();
		cnt+=1;
		for(int i=0;i<4;i++){
			if(t.x+dx[i]>=1 && t.x+dx[i]<=R && t.y+dy[i]>=1 && t.y+dy[i]<=C && vis[t.x+dx[i]][t.y+dy[i]]==0 && g[t.x+dx[i]][t.y+dy[i]]>g[t.x][t.y]){
				P add;
				add.x=t.x+dx[i];
				add.y=t.y+dy[i];
				vis[add.x][add.y]=cur;
				q.push(add);
			}
		}
	}
	return cnt;
}

int main(){
	cin>>R>>C;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			if(vis[i][j]==0){
				P pt;
				pt.x=i;
				pt.y=j;
				ans[cur]=bfs(pt);
				++cur;
			}
		}
	}
	int ansx=-1000;

	for(int i=1;i<=cur;i++){
		ansx=max(ansx,ans[i]);
	}
	cout<<ansx;
	return 0;
}