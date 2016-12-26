#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

struct Edge{
	int to;bool vis;
	Edge(){
		vis=false;
	}
};

Edge g[200100];
queue<Edge> q;
int in[200100];
int N;
inline void init(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>g[i].to;
		in[g[i].to]++;
	}
}

inline void toposort(){
	for(int i=1;i<=N;++i){
		if(in[i]==0){
			q.push(g[i]);
			g[i].vis=true;
		}
	}
	Edge K;
	while(q.size()){
		K=q.front();q.pop();
		if(--in[K.to]==0){
			g[K.to].vis=true;
			q.push(g[K.to]);
		}
	}
}

int main(){
	init();
	toposort();
	int ret=200010;
	for(int i=1;i<=N;++i){
		if(!g[i].vis){
			int ans=0;
			for(int j=i;j!=i || ans==0;j=g[j].to){
				++ans;
				g[j].vis=true;
			}
			ret=min(ret,ans);
		}
	}
	cout<<ret;
	return 0;
}