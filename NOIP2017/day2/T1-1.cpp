#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

struct Node{
	int id;
	double x,y,z;
	void init(int _id) {
		id = _id;
		scanf("%lf%lf%lf", &x, &y, &z);
	}
};

Node p[1010];
int fa[1010];
int top[1010], t;
int bot[1010], b;
int N;
double r,h;

int Find(int x) {
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}

inline void Union(int x,int y) {
	int fx = Find(x);
	int fy = Find(y);
	fa[fx] = fy;
}

inline bool SameSet(int x,int y) {
	return Find(x) == Find(y);
}

inline double dis(Node a,Node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

inline bool check(double a,double b){
	if (fabs(a-b)<1e-8) return 1;
	return a<b;
}

inline void _init() {
	for(int i=0;i<=N;++i) {
		fa[i] = i;
	}
	t=b=0;
}

inline void work() {
	for(int i=1;i<=N;i=-~i) {
		if(check(p[i].z, r)) {
			bot[++b] = p[i].id;
		}
		if(check(h-p[i].z, r)) {
			top[++t] = p[i].id;
		}
		for(int j=-~i;j<=N;j=-~j) {
			if(check(dis(p[i], p[j]), 2.0*r)) {
				Union(p[i].id, p[j].id);
			}
		}
	}
	for(int i=1;i<=t;i=-~i) {
		for(int j=1;j<=b;j=-~j) {
			if(SameSet(top[i], bot[j])) {
				puts("Yes");
				return;
			}
		}
	}
	puts("No");
}

int main() {
	int T;scanf("%d", &T);
	while(T--) {
		_init();
		scanf("%d%lf%lf", &N, &h, &r);
		for(int i=1;i<=N;++i) {
			p[i].init(i);
		}
		work();
	}
}