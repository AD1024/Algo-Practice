#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char g[110][110];

int map[110][110];
int N,M;

const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};

int main(){
	cin>>N>>M;
	char str[110];
	for(int i=1;i<=N;++i){
		cin>>str;
		for(int j=1;j<=M;++j){
			g[i][j]=str[j-1];
			if(g[i][j]=='*'){
				map[i][j]=-1;
			}
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			if(g[i][j]=='*'){
				for(int k=0;k<8;++k){
					if(i+dx[k]>=1 && i+dx[k]<=N && j+dy[k]<=M && j+dy[k]>=1){
						if(map[i+dx[k]][j+dy[k]]!=-1)
							map[i+dx[k]][j+dy[k]]+=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<M;++j){
			if(map[i][j]==-1){
				printf("*");
			}else{
				printf("%d",map[i][j]);
			}
		}
		if(map[i][M]==-1){
				printf("*\n");
			}else{
				printf("%d\n",map[i][M]);
			}
	}
	return 0;
}