#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct P{
	int x,y;
	void init(int i,int j){
		x=i;
		y=j;
	}
}list[10010];
bool cmp(P a,P b){
	return a.x+a.y<b.x+b.y;
}
int N,M,K;
int tot=0;
int main(){
	cin>>N>>M>>K;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			list[tot].init(i,j);
			++tot;
		}
	}
	sort(list,list+tot,cmp);
	int ans=0;
	for(int i=0;i<K;++i){
		ans+=(list[i].x+list[i].y)-1;
	}
	cout<<ans<<"\n";
	for(int i=K-1;i>=0;--i){
		for(int j=1;j<=list[i].x;++j){
			printf("(%d,1) ",j);
		}
		for(int j=2;j<=list[i].y;++j){
			printf("(%d,%d) ",list[i].x,j);
		}
		puts("");
	}
	return 0;
}