/*
ID: ccodera1
LANG: C++
TASK: castle
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define INF 0x3f3f3f3f
#define up(x) ((x >> 1) & 1)
#define down(x) ((x >> 3) & 1)
#define left(x) (x & 1)
#define right(x) ((x >> 2) & 1)
#define HASH(x,y) ((x-1)*M+y+250)

int M,N;
bool vis[100100];
int Rank[100 * 100];
int fa[100 * 100];
inline int Find(int x){
	int k = x;
	while(x!=fa[x]){
		x = fa[x];
	}
	int j;
	while(k != x){
		j = fa[k];
		fa[k] = x;
		k = j;
	}
	return x;
}
inline bool SameSet(int x,int y){
	return Find(x) == Find(y);
}
inline void Union(int x,int y){
	int fx = Find(x);
	int fy = Find(y);
	if(fx != fy){
		fa[fx] = fy;
	}
}
inline void init(){
	for(int i=1;i<=(M*M-M+N+250);++i) fa[i] = i;
}
inline void Solve1(){
	int k;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			k = Find(HASH(i,j));
			vis[k] = true;
			Rank[k] += 1;
		}
	}
	int ans1 = 0;
	for(int i=1;i<=M*M-M+N+250;++i){
		if(vis[i]){ 
			ans1++;
		}
	}
	int ans2 = -INF;
	for(int i=1;i<=M*M-M+N+250;++i){
		if(Rank[i]>ans2) ans2 = Rank[i];
	}
	cout<<ans1<<endl<<ans2<<endl;
}
inline void Solve2(){
	int ans1 = 0;int ans2[2];char dir;
	for(int j=1;j<=M;++j){
		for(int i=N;i>=1;--i){
			if(i>1 && !SameSet(HASH(i,j),HASH(i-1,j))){
				int merged = Rank[Find(HASH(i,j))] + Rank[Find(HASH(i-1,j))];
				if(merged > ans1){
					ans1 = merged;
					ans2[0] = i;
					ans2[1] = j;
					dir = 'N';
				}
			}
			if(j < M && !SameSet(HASH(i,j), HASH(i,j+1))){
				int merged = Rank[Find(HASH(i,j))] + Rank[Find(HASH(i,j+1))];
				if(merged > ans1){
					ans1 = merged;
					ans2[0] = i;
					ans2[1] = j;
					dir = 'E';
				}
			}
		}
	}
	cout<<ans1<<endl<<ans2[0]<<" "<<ans2[1]<<" "<<dir<<endl;
}
int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	cin>>M>>N;int tmp;
	init();
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			cin>>tmp;
			if(i > 1){
				if(!up(tmp)){
					Union(HASH(i,j),HASH(i-1,j));
				}
			}
			if(j > 1){
				if(!left(tmp)){
					Union(HASH(i,j),HASH(i,j-1));
				}
			}
		}
	}
	Solve1();Solve2();
	return 0;
}