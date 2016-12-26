#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define INF 0xfffff

struct Point{
	double x,y;
	int v;
	int id;
}list[110];

struct Edge{
	int u,v;
	double w;
};

vector<Edge> g[110];
int N,M;
int cur=0;
bool vis[110];
double dist[110];
queue<int> q;

inline double calc(Point a,Point b){
	double dist = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	dist=fabs(dist);
	return dist;
}

inline void SPFA(int s){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=N;++i){
		dist[i]=INF;
	}
	dist[s]=0;
	q.push(s);
	int k;
	int v;
	while(q.size()){
		k=q.front();
		q.pop();
		vis[k]=true;
		for(int i=0;i<g[k].size();++i){
			v=g[k][i].v;
			if(dist[v]>dist[k]+g[k][i].w){
				dist[v]=dist[k]+g[k][i].w;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
		vis[k]=false;
	}
	return;
}


int main(){
	cin>>N;
	Point P;
	for(int i=1;i<=N;++i){
		double x,y;
		cin>>x>>y;
		P.x=x;P.y=y;
		P.id=i;
		list[++cur]=P;
	}
	cin>>M;
	int u,v;
	Edge E;
	for(int i=1;i<=M;++i){
		cin>>u>>v;
		E.u=u;E.v=v;
		E.w=calc(list[u],list[v]);
		g[u].push_back(E);
		E.u^=E.v^=E.u^=E.v;
		g[v].push_back(E);
	}
	cin>>u>>v;
	SPFA(u);
	printf("%.2f\n",dist[v]);
	return 0;
}