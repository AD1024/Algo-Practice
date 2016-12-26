#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int b[100010];
int main(){
	int N;
	scanf("%d",&N);
	int x;
	for(int i=0;i<N;++i){
		scanf("%d",&x);
		b[x]++;
	}
	for(int i=0;i<=100010;++i){
		if(b[i]){
			for(int j=1;j<=b[i];++j){
				printf("%d ",i);
			}
		}
	}
	return 0;
}