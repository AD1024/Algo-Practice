#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> g[100010];
queue<int> q;
int path[100010];
int N,M;
int in[100010];
int ans[100010];
vector<int> topo;
inline void init(){
    cin>>N>>M;
    int u,v;
    for(int i=0;i<M;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        in[v]++;
    }
    //memset(dist,0,sizeof(dist));
    memset(ans,0,sizeof(ans));
    path[1]=-1;
}


inline void toposort(){
	stack<int> t;
	int tot=N;
	for(int i=1;i<=N;i++){
		if(in[i]==0){
			t.push(i);
			ans[i]=1;
		}
	}
	while(!t.empty()){
		int k=t.top();
		t.pop();
		topo.push_back(k);
		for(int i=0;i<g[k].size();++i){
			in[g[k][i]]--;
			if(!in[g[k][i]]) t.push(g[k][i]);
		}
	}
}

inline void work(){
	for(int j=0;j<topo.size();++j){
    	int k=topo[j];
    	for(int i=0;i<g[k].size();++i){
    		if(ans[g[k][i]]<ans[k]+1){
    			ans[g[k][i]]=ans[k]+1;
    		}
    	}
    }
    for(int i=1;i<=N;i++){
    	printf("%d\n",ans[i]);
    }
}

int main(){
    init();
    toposort();
    work();
    return 0;
}