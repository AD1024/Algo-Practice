#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct P{
	int x[21],y[21];
	int T;
};

P man;
int map[110][110];
char g[110][110];
int W,H;
int s=0;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
inline void init(){
	for(int i=0;i<H;++i){
		cin>>g[i];
	}
	s=0;
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			if(g[i][j]=='D'){
				man.x[s]=i;
				man.y[s]=j;
				++s;
			}
		}
	}
	man.T=0;
}

int BFS(int x){
	queue<P> q;
	q.push(man);
	map[man.x[0]][man.y[0]]=x;
	P k;
	while(q.size()){
		k=q.front();q.pop();
		int j;
		P add;
		for(int i=0;i<4;++i){
			for(j=0;j<s;++j){
				add.x[j]=k.x[j]+dx[i];
				add.y[j]=k.y[j]+dy[i];
				if(add.x[j]<0 || add.y[j]<0 || add.x[j]>=H || add.y[j]>=W){
					break;
				}
				if(g[add.x[j]][add.y[j]]=='O') break;
			}
			if(j!=s) continue;
			if(map[add.x[0]][add.y[0]]==x) continue;
			else map[add.x[0]][add.y[0]]=x;
			add.T=k.T+1;
			for(int j=0;j<s;++j){
				if(g[add.x[j]][add.y[j]]=='Q') return add.T;
			}
			q.push(add);
		}	
	}
	return -1;
}

int flag=0;
int main(){
	while(cin>>H>>W){
		if(H==0 && W==0) break;
		init();
		int ans=BFS(++flag);
		if(ans==-1){
			cout<<"Impossible\n";
		}else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}

