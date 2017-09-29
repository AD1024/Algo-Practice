#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

#define MAXN 151000

struct Edge{
	int v;
	ll w;
	int next;
};

ll f[MAXN];
ll ssorted[MAXN];
ll dist[MAXN];
Edge e[MAXN];
int First[MAXN];
bool vis[MAXN],rem[MAXN];
int EID=0;
int N,M,U,V;
ll S;

template <typename T>
inline void read(T &a){
	a = 0;
	char ch = getchar();
	while(ch > '9' || ch < '0') ch=getchar();
	while(ch>='0' && ch <= '9'){
		a = a * 10 + ch - '0';
		ch = getchar();
	}
}

int heap[MAXN<<1];

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1
#define dt(x) dist[heap[x]]


struct Heap{
	int _size;
	Heap(){
		_size = 0;
	}

	void pushUp(int i){
		while(fa(i) >= 1){
			if(dt(i) < dt(fa(i))){
				swap(heap[i],heap[fa(i)]);
				i=fa(i);
			}else break;
		}
	}
	void pushDown(int i){
		int l,r,k;
		while(lson(i) <= _size){
			k = i;l = lson(i);r = rson(i);
			if(dt(k) > dt(l)){
				k = l;
			}
			if(r <= _size && dt(k) > dt(r)){
				k = r;
			}
			if(k != i){
				swap(heap[i],heap[k]);
				i=k;
			}else break;
		}
	}
	void insert(int i){
		heap[++_size]=i;
		pushUp(_size);
	}
	int top(){
		return heap[1];
	}
	void pop(){
		heap[1] = heap[_size--];
		pushDown(1);
	}
	bool empty(){
		return _size == 0;
	}
};

Heap q;

inline void addEdge(int u,int v,int w){
	e[EID].next = First[u];
	e[EID].v=v;
	e[EID].w=w;
	First[u] = EID++;
}

inline bool dij(ll value){
	if(f[U] > value || f[V] > value) return false;
	for(int i=1;i<=N;++i){
		vis[i]=rem[i]=false;
		dist[i]=0x3f3f3f3f3f3f3f;
		if(f[i]>value){
			rem[i]=true;
		}
	}
	dist[U]=0;
	q.insert(U);int k,v;
	while(!q.empty()){
		k = q.top();
		q.pop();
		if(vis[k]) continue;
		vis[k]=true;
		for(int i=First[k];~i;i=e[i].next){
			v=e[i].v;
			if(!rem[v]){
				// cout<<v<<" ";
				if(dist[v] > dist[k] + e[i].w){
					dist[v] = dist[k] + e[i].w;
					q.insert(v);
				}
			}
		}
	}
	return dist[V] <= S;
}

int main(){
	memset(First,-1,sizeof(First));
	read(N);read(M);read(U);read(V);read(S);
	for(int i=1;i<=N;++i) read(f[i]);
	int a,b;
	ll c;
	for(int i=1;i<=M;++i){
		read(a);read(b);read(c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}
	memcpy(ssorted,f,sizeof(f));
	sort(ssorted+1,ssorted+1+N);
	if(dij(ssorted[N])){
		int l,r,mid;
		l=1;r=N;
		while(l<r){
			mid = (l+r)>>1;
			if(dij(ssorted[mid])){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		printf("%lld\n",ssorted[l]);
	}else{
		puts("-1");
	}
	return 0;
}
