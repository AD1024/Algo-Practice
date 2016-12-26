#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAXN 1001

int EID=1;

struct E{
	int u,v,w;
	int First,Next;
	E(){
		First=Next=-1;
	}
}Edges[MAXN];
int M,N;
inline void addEdge(int F,int T,int W){
	Edges[EID].Next=Edges[F].First;
	Edges[EID].w=W;
	Edges[EID].u=F;
	Edges[EID].v=T;
	Edges[F].First=EID++;
}

inline void Traverse(int s){
	for(int i=Edges[s].First;i!=-1;i=Edges[i].Next){
		cout<<Edges[i].u<<" "<<Edges[i].v;
		puts("");
	}
}

int main(){
	cin>>N>>M;
	while(M--){
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
	}
	Traverse(1);
	return 0;
}
