#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <time.h>
using namespace std;

int a[10100];

bool ok;

bool vis[20200];

int visSum[3628800];

int N;

void f(int dep, int sum){
	if(dep > N){
		ok = true;
	}else{
		for(int i=1;i<=N;++i){
			if(ok) return;
			if(!vis[i]){
				vis[i] = true;
				if(!visSum[(sum+i)%N]){
					a[dep] = i;
					visSum[(sum+i)%N] = true;
					f(dep+1,sum+i);
					visSum[(sum+i)%N] = false;
				}
				vis[i] = false;
			}
		}
	}
}

void f1(int dep, long long sum){
	if(dep > N){
		ok = true;
	}else{
		for(int i=1;i<=N;++i){
			if(ok) return;
			if(!vis[i]){
				vis[i] = true;
				if(!visSum[(sum*i)%N]){
					a[dep] = i;
					visSum[(sum*i)%N] = true;
					f1(dep+1,sum*i);
					visSum[(sum*i)%N] = false;
				}
				vis[i] = false;
			}
		}
	}
}

int X,T;

int main(){
	scanf("%d%d",&X,&T);
	while(T--){
		scanf("%d",&N);
		srand(time(NULL));
		ok = false;
		memset(visSum,false,sizeof(visSum));
		memset(vis,false,sizeof(vis));
		if(X == 1){
			if(N<=13){
				f(1,0);
				if(ok){
					printf("2 ");
					for(int i=1;i<=N;++i){
						printf("%d ",a[i]);
					}
				}else{
					putchar('0');
				}
			}else{
				if(N & 1){
					putchar('0');
				}else{
					putchar('1');
				}
			}
		}else{
			if(N<=20){
				f1(1,1);
				if(ok){
					printf("2 ");
					for(int i=1;i<=N;++i){
						printf("%d ",a[i]);
					}
				}else{
					putchar('0');
				}
			}else{
				printf("1");
			}
		}
		putchar('\n');
	}
	return 0;
}