#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 401000
#define INF 0x3f3f3f3f

int First[MAXN],Next[MAXN],V[MAXN],W[MAXN];

int EID=1;
int Size[MAXN];
bool visz[MAXN];int dep[MAXN];
int depth[MAXN];
int maxWeight[MAXN];
int root;int N,tot,cnt;

int S,E;int ans;

inline int read(){
	char ch;
	int a=0;
	ch = getchar();
	while(ch>'9' || ch<'0'){
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		a = a*10 + ch-'0';
		ch=getchar();
	}
	return a;
}

inline void AddEdge(int u,int v,int w){
	++tot;
	Next[EID] = First[u];
	W[EID] = w;
	V[EID] = v;
	First[u] = EID++;
}

void getRoot(int v,int fa){
	Size[v] = 1;
	maxWeight[v] = 0;
	for(int i=First[v];i;i=Next[i]){
		int to = V[i];
		if(to != fa && !visz[to]){
			getRoot(to,v);
			Size[v] += Size[to];
			maxWeight[v] = max(maxWeight[v],Size[to]);
		}
	}
	maxWeight[v] = max(maxWeight[v],cnt-Size[v]);
	if(maxWeight[v]<maxWeight[root]){
		root=v;
	}
}

inline void work(){
	sort(depth+1,depth+1+tot);
	int l=1;
	while(depth[l] == 0) ++l;
	int r=cnt;int m;
	while(l<r){
		m=depth[l]+depth[r]-2;
		if(m<S) ++l;
		else --r;
		if(m>=S && m<=E){
			ans = min(ans,m);
		}
	}
}

void dfs(int v,int fa){
	for(int i=First[v];i;i=Next[i]){
		if(V[i]!=fa && !visz[V[i]]){
			dep[V[i]] = (dep[v] + W[i]);
			dfs(V[i],v);
		}
	}
	depth[++tot] = dep[v];
}

void solve(int v,int fa){
	dep[v]=1;
	tot=0;
	dfs(v,fa);
	work();
	visz[v]=true;
	for(int i=First[v];i;i=Next[i]){
		int to = V[i];
		if(!visz[to]){
			cnt = Size[to];
			root = 0;
			getRoot(to,v);
			solve(root,v);
		}
	}
}

int main(){
	// scanf("%d%d%d",&N,&S,&E);
	N=read();S=read();E=read();int f,t,w;
	for(int i=1;i<N;++i){
		// scanf("%d%d%d",&f,&t,&w);
		f=read();t=read();w=read();
		AddEdge(f,t,w);AddEdge(t,f,w);
	}
	maxWeight[0] = INF;
	cnt = N;
	root = 0;
	getRoot(1,root);
	ans = INF;
	solve(root,0);
	if(ans == INF){
		puts("-1");
	}else{
		printf("%d\n",ans);
	}
	return 0;
}