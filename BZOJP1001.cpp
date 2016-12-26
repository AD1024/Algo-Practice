#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 1010

struct Edge{
	u,v,w;
};

vector<Edge> g[MAXN];
queue<int> q;
vis[1010];
int M,N;


inline void init(){
	int VID=1;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			int w;
			cin>>w;
			Edge E,E1;
			E.u=VID;
			E.v=++VID;
			E.w=w;
			g[E.u].push_back(E);
			E1=E;
			E.u=VID;
			E.v=VID-1;
			g[E.v].push_back(E);
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
}

