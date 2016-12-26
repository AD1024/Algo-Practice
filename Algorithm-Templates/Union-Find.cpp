#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int fa[10001];
int N,M;

int Find(int x){
	int xx=x;
	while(x!=fa[x]) x=fa[x];
	int j;
	while(xx!=x){
		j=fa[xx];
		fa[xx]=x;
		xx=j;
	}
	return x;
}

inline void Union(int x,int y){
	int fx=Find(x);int fy=Find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}

inline void init(){
	for(int i=1;i<=N;++i) fa[i]=i;
}

int main(){
	cin>>N>>M;
	init();
	int op,a,b;
	while(M--){
		cin>>op>>a>>b;
		if(op==1){
			Union(a,b);
		}else{
			if(Find(a)==Find(b)){
				puts("Y");
			}else{
				puts("N");
			}
		}
	}
	return 0;
}