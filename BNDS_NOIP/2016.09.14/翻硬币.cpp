#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
#define MP(x,y) make_pair(x,y)
struct Pos{
	int up,down;
	int step;
	Pos(){}
	Pos(int u,int d,int s){
		up=u;
		down=d;
		step=s;
	}
};

map< pair<int,int> ,bool> vis;
bool found=false;
queue<Pos> q;
string start;

int M,N,K;

void BFS(){
	vis[make_pair(M,N-M)]=true;
	q.push(Pos(M,N-M,0));
	Pos k;
	while(q.size()){
		k=q.front();q.pop();
		if(k.down==N && k.up==0){
			cout<<k.step;
			found=true;
			return;
		}else{
			int U,D;
			for(int i=0;i<=K;++i){
				if(i<=k.up && k.down>=K-i){
					U=k.up-i;
					U+=K-i;
					D=k.down+i;
					D-=K-i;
					if(!vis[MP(U,D)]){
						vis[MP(U,D)]=true;
						Pos add=Pos(U,D,k.step+1);
						q.push(add);
					}
				}
				if(i<=k.down && k.up>=K-i){
					D=k.down-i;
					D+=K-i;
					U=k.up+i;
					U-=K-i;
					if(!vis[MP(U,D)]){
						vis[MP(U,D)]=true;
						Pos add=Pos(U,D,k.step+1);
						q.push(add);
					}
				}
			}
		}
	}
}

int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	cin>>N>>M>>K;
	BFS();
	if(!found){
		puts("No solution!");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}