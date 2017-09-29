#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

struct Edge{
	int f,t,w;
	Edge(){}
	Edge(int u,int v,int k){
		f = u;
		t = v;
		w = k;
	}
};

struct Pair{
	int w;
	int step;
	Pair(){
		w = INF;
		step = INF;
	}
};

const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};

vector<Edge> g[3000000];
queue<int> q;
Pair ans[3000000];

int cnt;

char map[510][510];
int nid[510][510];
bool vis[3000000];

int M,N;

inline void addEdge(int f,int t,int w){
	g[f].push_back(Edge(f,t,w));
}

int main(){
	memset(nid,-1,sizeof(nid));
	ios::sync_with_stdio(false);
	cin>>N>>M;
	int x1,y1,x2,y2;
	cin>>x1>>y1;
	cin>>x2>>y2;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			if(map[i][j] == '0') continue;
			else{
				if(nid[i][j]<0) nid[i][j] = ++cnt;
				for(int k=0;k<8;++k){
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(nx > 0 && nx <= N && ny > 0 && ny <=M && map[nx][ny] != '0'){
						if(nid[nx][ny]<0) nid[nx][ny] = ++cnt;
						addEdge(nid[i][j],nid[nx][ny],int(map[i][j] != map[nx][ny]));
					}
				}
			}
		}
	}
	ans[nid[x1][y1]].w = 0;
	ans[nid[x1][y1]].step = 1;
	vis[nid[x1][y1]] = true;
	q.push(nid[x1][y1]);
	int k;
	while(!q.empty()){
		k = q.front();
		q.pop();
		for(int i=0;i<g[k].size();++i){
			int to = g[k][i].t;
			if(ans[to].w > ans[k].w + g[k][i].w){
				ans[to].w = ans[k].w + g[k][i].w;
				ans[to].step = ans[k].step + 1;
				if(!vis[to]){
					vis[to] = true;
					q.push(to);
				}
			}else if(ans[to].w == ans[k].w + g[k][i].w){
				if(ans[to].step > ans[k].step + 1){
					ans[to].step = ans[k].step + 1;
					if(!vis[to]){
						vis[to] = true;
						q.push(to);
					}
				}
			}
		}
		vis[k] = false;
	}
	if(ans[nid[x2][y2]].w == INF && ans[nid[x2][y2]].step == INF){
		cout<<"0 0";
	}else{
		cout<<ans[nid[x2][y2]].step<<" "<<ans[nid[x2][y2]].w;
	}
	return 0;
}