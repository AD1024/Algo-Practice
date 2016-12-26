#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 1001;
vector<int> g[MAXN];
int M,N,Q;

inline void init(){
	scanf("%d%d",&N,&M);
	int F,T;
	for(int i=0;i<M;++i){
		scanf("%d%d",&F,&T);
		g[F].push_back(T);
		g[T].push_back(F);
	}
}

int main(){

}