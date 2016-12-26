#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

int g[110][110];
int vis[110];
int N;int path[110];
int dist[110];
queue<int> q;
stack<int> ans;
inline void LPFA(int s){
	vis[s]=true;
	q.push(s);
	int k;int v;
	dist[s]=0;
	while(!q.empty()){
		k=q.front();q.pop();
		vis[k]=false;
		for(int i=1;i<=N;++i){
			if(g[k][i]){
				if(dist[i]<dist[k]+g[k][i]){
					dist[i]=dist[k]+g[k][i];
					path[i]=k;
					// for(int i=1;i<=N;++i){
					// 	cout<<path[i]<<" ";
					// }
					// puts("");
					if(!vis[i]){
						vis[i]=true;
						q.push(i);
					}
				}
			}
		}
	}
}
int in[110];int out[110];
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			scanf("%d",&g[i][j]);
			if(g[i][j]){
				in[j]++;
				out[i]++;
			}
		}
	}
	int start=1;
	for(int i=1;i<=N;++i){
		if(in[i]==0){
			start=i;break;
		}
	}
	LPFA(start);

	int maxn=-0x3f3f3f;
	// for(int i=1;i<=N;++i){
	// 	// cout<<dist[i]<<" ";
	// 	if(dist[i]>maxn) maxn=dist[i],start=i;
	// }
	for(int i=1;i<=N;++i){
		if(out[i]==0){
			start=i;
		}
	}
	while(start){
		ans.push(start);
		start=path[start];
	}
	while(!ans.empty()){
		printf("%d ",ans.top());ans.pop();
	}
	return 0;
}