#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 10010

int First[MAXN],Next[MAXN],u[MAXN],v[MAXN];

int EID = 1;

bool vis[MAXN];

inline void addEdge(int x,int y){
	Next[EID] = First[x];
	v[EID] = y;
	First[x] = EID++;
}

bool ok;

int N,K,P;
int M;

void DFS(int u){
	if(u == K){
		ok = true;
		return;
	}
	for(int i=First[u];i;i=Next[i]){
		if(ok) return;
		if(!vis[v[i]]){
			vis[v[i]] = true;
			DFS(v[i]);
			vis[v[i]] = false;
		}
	}
}

inline int BFS(int x){
	queue<int> q;
	int ans = -1;
	memset(vis,false,sizeof(vis));
	q.push(x);int k;
	while(q.size()){
		k = q.front();
		q.pop();
		if(vis[k]) continue;
		vis[k] = true;
		ans++;
		for(int i=First[k];i;i=Next[i]){
			q.push(v[i]);
		}
	}
	return ans;
}

int main(){
	cin>>N>>K>>P;
	cin>>M;
	for(int i=1;i<=M;++i){
		int f,t;cin>>f>>t;
		addEdge(f,t);
		addEdge(t,f);
	}
	DFS(P);
	cout<<BFS(K)<<endl;
	cout<<(ok?"the poor rabbit":"the unlucky fox");
	return 0;
}