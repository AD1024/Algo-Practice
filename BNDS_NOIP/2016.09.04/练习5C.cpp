#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[1001][1001];
int used[1001];

inline void print(){
	for(int i=1;i<=4;++i){
		for(int j=1;j<4;++j){
			printf("%d ",map[i][j]);
		}
		printf("%d\n",map[i][4]);
	}
	puts("");
}

void f(int idx){
	if(idx>4){
		print();
	}else{
		for(int i=1;i<4;++i){
			if(used[i]+1<=2){
				used[i]++;
				map[idx][i]=1;
			}else continue;
			for(int j=i+1;j<=4;++j){
				if(used[j]+1<=2){
					used[j]++;
					map[idx][j]=1;
					f(idx+1);
					used[j]--;
					map[idx][j]=0;
				}
			}
			used[i]--;
			map[idx][i]=0;
		}
	}
}

int main(){
	f(1);
	return 0;
}