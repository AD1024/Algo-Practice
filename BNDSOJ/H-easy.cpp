#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;


struct pos{
	int x,y;
	pos(){}
	pos(int xx,int yy){
		x=xx;
		y=yy;
	}
};

map<pos,int> g;

int ans=0;
int main(){
	int N;
	cin>>N;
	int q;
	while(cin>>q){
		if(q==3) break;
		else if(q==1){
			int xx,yy;
			cin>>xx>>yy;
			int inc;cin>>inc;
			g[pos(xx,yy)]++;
		}else if(q==2){
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			int ot = g[pos(x1,y1)]+g[pos(x2,y2)];
			cout<<(ot^ans);
			puts("");
			ans=ot^ans;
		}
	}
	return 0;
}