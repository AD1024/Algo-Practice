#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;

struct Node{
	int id;
	double x,y,z;
};
Node p[1005];

int n,q[1005];
double h,r;

bool vis[1005];
inline double dis(Node a,Node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
inline bool check(double a,double b){
	if (fabs(a-b)<1e-8) return 1;
	return a<b;
}
inline bool bfs(){
	int front=0,rear=0;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (check(p[i].z,r)) {
			q[rear++]=i,vis[i]=1;
		}
	while (front<rear) {
		int u=q[front++];
		for (int v=1;v<=n;v++){
			if (!vis[v]){
				if (check(dis(p[u],p[v]),r*2.0)){
					q[rear++]=v,vis[v]=1;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	if (vis[i]) {
		if (check(h-p[i].z,r)) {
			return 1;
		}
	}
	return 0;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%lf%lf",&n,&h,&r);
		for (int i=1;i<=n;i++) {
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
		}
		if (bfs()) puts("Yes"); else puts("No");
	}
	return 0;
}
