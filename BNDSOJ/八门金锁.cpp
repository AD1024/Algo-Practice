#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long

struct Edge{
	int u,v;
	ll w;
	int next;
	bool operator < (const Edge e)const{
		return w<e.w;
	}
};

ll f[101000];
ll ff[101000];
Edge e[101000];
int First[101000];
bool vis[101000];
bool rem[101000];
ll dist[101000];
int EID = 0;

int N,M,U,V,S;

deque<int> q;

inline void AddEdge(int u,int v,ll w){
	e[EID].next = First[u];
	e[EID].u = u;
	e[EID].v = v;
	e[EID].w = w;
	First[u] = EID++;
}

inline bool ok(ll value){
	if(f[U] > value || f[V] > value) return false;
	memset(vis,false,sizeof(vis));
	memset(rem,false,sizeof(rem));
	for(int i=1;i<=N;++i) dist[i] = 0x3f3f3f3f3fL;
	for(int i=1;i<=N;++i) if(f[i] > value) rem[i] = true;
	dist[U]=0;
	vis[U]=true;
	q.push_back(U);
	int k,v;
	while(!q.empty()){
		k = q.front();q.pop_front();
		vis[k] = false;
		for(int i=First[k];~i;i=e[i].next){
			if(!rem[e[i].v]){
				v = e[i].v;
				if(dist[v] > dist[k] + e[i].w){
					dist[v] = dist[k] + e[i].w;
					if(!vis[v]){
						vis[v] = true;
						if(!q.empty()){
							if(dist[v] > dist[q.front()]){
								q.push_back(v);
							}else{
								q.push_front(v);
							}
						}else q.push_back(v);
					}
				}
			}
		}
	}
	// cout<<dist[V]<<endl;
	return dist[V] <= S;
}

int main(){
	memset(First, -1 ,sizeof(First));
	ios::sync_with_stdio(false);
	cin>>N>>M>>U>>V>>S;
	int a,b,c;
	for(int i=1;i<=N;++i) cin>>f[i];
	for(int i=1;i<=M;++i){
		cin>>a>>b>>c;
		AddEdge(a,b,c);
		AddEdge(b,a,c);
	}
	memcpy(ff,f,sizeof(f));
	sort(ff+1,ff+1+N);
	int l = 1,r=N;int mid;
	if(!ok(ff[N])){
		cout<<"-1";
		return 0;
	}
	while(l<r){
		mid = (l+r)>>1;
		if(ok(ff[mid])){
			r = mid;
		}else{
			l = mid+1;
		}
	}
	cout<<ff[l];
	return 0;
}