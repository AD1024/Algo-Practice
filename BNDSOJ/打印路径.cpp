#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int p[10100];
int N;

void dfs(int x,int step) {
	if(x > N) return;
	if(x == N){
		for(int i=0;i<step;++i){
			printf("%d-", p[i]);
		}
		printf("%d\n", N);
	}else{
		p[step] = x;
		dfs(x+1, step+1);
		dfs(x+2, step+1);
	}

}

int main(){
	scanf("%d", &N);
	dfs(0, 0);
	return 0;
}