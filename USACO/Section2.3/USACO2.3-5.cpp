/*
ID: ccodera1
LANG: C++
TASK: concom
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int First[10100],Next[10100],u[10100],v[10100],w[10100];

int EID = 1;
int N;

bool vis[10100];

inline void addEdge(int f,int t,int p){
	Next[EID] = First[f];
	v[EID] = t;
	w[EID] = p;
	First[f] = EID++;
}

struct Pair{
	int a,b;
	Pair(){}
	Pair(int f,int n){
		a = f;
		b = n;
	}
};

bool cmp(Pair a,Pair b){
	if(a.a != b.a){
		return a.a<b.a;
	}else{
		return a.b<b.b;
	}
}

Pair ans[10100];
int c[10100];
int cur;

void dfs(int fa,int t){
	if(fa != t){
		ans[cur++] = Pair(fa,t);
	}
	for(int i=First[t];i;i=Next[i]){
		c[v[i]] += w[i];
		if(c[v[i]]>50){
			if(!vis[v[i]]){
				vis[v[i]] = true;
				dfs(fa,v[i]);
			}
		}
	}
}

int main(){
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	cin>>N;int f,t,W;
	int m=0x3f3f3f3f,n=-0x3f3f3f3f;
	for(int i=1;i<=N;++i){
		cin>>f>>t>>W;
		int ttt = min(f,t);
		int tt = max(f,t);
		m = min(m,ttt);
		n = max(n,tt);
		addEdge(f,t,W);
	}
	for(int i=m;i<=n;++i){
		memset(vis,false,sizeof(vis));
		memset(c,0,sizeof(c));
		dfs(i,i);
	}
	sort(ans,ans+cur,cmp);
	for(int i=0;i<cur;++i){
		cout<<ans[i].a<<' '<<ans[i].b<<"\n";
	}
	return 0;
}