#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int Rank[10100];
int fa[10100];

inline int Find(int x){
	int k=x;
	while(x != fa[x]) x = fa[x];
	int j;
	while(k != x){
		j = fa[k];
		fa[k] = x;
		k = j;
	}
	return x;
}

inline bool SameSet(int x,int y){
	if(Find(x) == Find(y)){
		return true;
	}else return false;
}
inline void Union(int x,int y){
	int fx = Find(x);int fy = Find(y);
	if(fx != fy){
		Rank[fy] += Rank[fx];
		fa[fx] = fy;
	}
}

int main(){
	int N,K,P;cin>>N>>K>>P;
	int M;cin>>M;int u,v;
	for(int i=1;i<=N;++i){
		fa[i] = i;
		Rank[i] = 1;
	}
	while(M--){
		cin>>u>>v;
		Union(u,v);
	}
	cout<<Rank[Find(K)] - 1<<endl;
	if(SameSet(P,K)){
		puts("the poor rabbit");
	}else{
		puts("the unlucky fox");
	}
	return 0;
}