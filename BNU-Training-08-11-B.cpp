#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,u,v) for(int i=u;i<=v;++i)
bool g[1010][1010];
int a[1010];
int K;
int cur=0;
int p1,p2;
int cnt=0;
int main(){
	cin>>K;
	while(K){
		a[++cnt]=K%2;
		K/=2;
	}
	int cr=3;
	g[1][3]=true;
	reverse(a+1,a+cnt+1);
	cur=cnt;
	p1=3;p2=1;
	REP(i,2,cur){
		g[p1][++cr]=true;
		g[p1][++cr]=true;++cr;
		p1=cr;
		g[cr-1][cr]=g[cr-2][cr]=true;
		g[p2][++cr]=true;
		g[cr][cr+1]=true;
		cr++;
		if(a[i]){
			g[cr-2][cr]=true;
		}
		p2=cr;
	}
	g[p1][2]=true;
	cout<<cr<<"\n";
	REP(i,1,cr){
		REP(j,1,cr){
			if(g[i][j]){
				g[j][i]=true;
			}
			if(g[j][i]){
				g[i][j]=true;
			}
			if(g[i][j]){
				cout<<'Y';
			}else cout<<'N';
		}
		puts("");
	}
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,u,v) for(int i=u;i<=v;++i)
#define MAXN 100;

bool g[1010][1010];
int a[1010];
int K;
int cur=0;
int p1,p2;
int cnt=0;

inline void alter(int x,int y){
	g[x][y]=g[y][x]=true;
}
int main(){
	cin>>K;
	memset(g,0,sizeof(g));
	alter(1,3);
	alter(1,4);
	alter(2,MAXN);
	for(int i=3;i<60;i+=2){
		alter(i,i+2);
		alter(i,i+3);
		alter(i+1,i+2);
		alter(i+1;i+3);
	}
	REP(i,63,MAXN-1){
		alter(i,i+1);
	}
	for(int i=30;i!=0;--i){
		if(K>=(1<<i)){
			K-=(1<<i);
			alter((i<<1)+1,63+i);
			alter((i<<1)+2,63+i);
		}
	}
	if(K) alter(1,63);
	cout<<100<<"\n";
	REP(i,1,MAXN){
		REP(j,1,MAXN){
			
		}
	}
}
*/