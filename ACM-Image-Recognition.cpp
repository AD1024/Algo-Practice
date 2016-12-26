#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10001;

int N;

char g[MAXN][MAXN];

int ANS=0;

inline bool findEdge1(int x,int y){
	int i=x;
	int j=y;
	int cntx=0;
	int cnty=0;
	for(;i<N && j<N;){
		if(g[x][i]=='1'){
			cntx++;
		}else if(g[x][i+1]=='0') return false;
		if(g[j][y]=='1'){
			cnty++;
		}else if(g[j+1][y]=='0') return false;
	}
	return cntx=cnty;
}

inline bool findEdge(int x,int y){
	int i=x,j=y;
	int cntx=0;int cnty=0;
	for(;i<N && j<N;){
		if(g[x][j]=='1'){
			++cntx;
		}else{
			if(g[x][j+1]=='0') return false;
		}
		if(g[i][y]=='1'){
			++cnty;
		}else if(g[i][y+1]=='0') return false;
		++i;++j;
	}
	if(cnty!=cntx) return false;
	else return findEdge1(y+cnty,x+cntx);
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%s",g[i]);
		for(int j=0;j<N;j++){
			if(g[i][j]=='1'){
				++ANS;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(findEdge(i,j)) ANS+=1;
		}
	}
	cout<<ANS;
	return 0;
}