/*
ID: ccodera1
LANG: C++
TASK: ttwo
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char g[15][15];

bool vis[15][15][15][15][5][5];
int x1,y1,x2,y2;
int main(){
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	for(int i=1;i<=10;++i){
		for(int j=1;j<=10;++j){
			cin>>g[i][j];
			if(g[i][j]=='C'){
				x2=i;
				y2=j;
			}
			if(g[i][j]=='F'){
				x1=i;
				y1=j;
			}
		}
	}
	int T=0;
	int m,n;
	m=n=0;
	while(1){
		if(x1==x2 && y1==y2){
			cout<<T<<endl;
			return 0;
		}
		++T;
		if(m==0 && x1-1>=1 && g[x1-1][y1]!='*') --x1;
		else if(m==1 && y1+1<=10 && g[x1][y1+1]!='*') ++y1;
		else if(m==2 && x1+1<=10 && g[x1+1][y1]!='*') ++x1;
		else if(m==3 && y1-1>=1 && g[x1][y1-1]!='*') --y1;
		else m=(m+1)%4;

		if(n==0 && x2-1>=1 && g[x2-1][y2]!='*') --x2;
		else if(n==1 && y2+1<=10 && g[x2][y2+1]!='*') ++y2;
		else if(n==2 && x2+1<=10 && g[x2+1][y2]!='*') ++x2;
		else if(n==3 && y2-1>=1 && g[x2][y2-1]!='*') --y2;
		else n=(n+1)%4;

		if(vis[x1][x2][y1][y2][n][m]) break;
		else vis[x1][x2][y1][y2][n][m]=true;
	}
	puts("0");
	return 0;
}