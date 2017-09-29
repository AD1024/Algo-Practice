#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int fa[101000];

int mat[20][20];

int N;

inline void init(){
	for(int i=1;i<=N*100+N*10;++i) fa[i] = i;
}

inline int Find(int x){
	int k = x;
	while(x!=fa[x]) x = fa[x];
	int j;
	while(k != x) {
		j = fa[k];
		fa[k] = x;
		k = j;
	}
	return x;
}

inline void Union(int x,int y){
	int fx = Find(x);int fy = Find(y);
	if(fx != fy) {
		fa[fx] = fy;
	}
}

inline bool SameSet(int x,int y) {
	return Find(x) == Find(y);
}

inline bool ok(int x,int y){
	return x <= N && x >= 1 && y <= N && y >= 1 && mat[x][y] == 0;
}

inline int Hash(int x,int y) {
	return x * 100 + y;
}

inline void work(int x,int y){
	int nx = x+1;int ny = y;
	if(ok(nx,ny)) {
		// cout<<nx<<" "<<ny<<endl;
		Union(Hash(x,y), Hash(nx,ny));
	}
	nx = x;ny = y-1;
	if(ok(nx,ny)) {
		// cout<<nx<<" "<<ny<<endl;
		Union(Hash(x,y), Hash(nx,ny));
	}
}

int main(){
	scanf("%d", &N);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			scanf("%d", &mat[i][j]);
		}
	}
	init();
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(!mat[i][j]) {
				work(i,j);
			}
		}
	}
	if(SameSet(Hash(1, 1), Hash(N,N))) {
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}