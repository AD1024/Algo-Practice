#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


#define MAXN 1001000
int dist[MAXN];
int N;int L,M;

inline bool ok(int x){
	int ans=0;
	int last=0;
	for(int i=1;i<N;++i){
		if(dist[i]-last<x){
			++ans;continue;
		}
		last=dist[i];
	}
	return ans<=M;
}
#define Mid(x,y) (x+y)>>1
int main(){
	cin>>L>>N>>M;
	int l,r;
	r=L;
	for(int i=1;i<=N;++i){
		cin>>dist[i];
		if(dist[i]-dist[i-1]<l){
			l=dist[i]-dist[i-1];
		}
	}
	dist[++N]=L;
	// cout<<l<<" "<<r<<endl;
	while(l+1<r){
		int mid=Mid(l,r);
		// cout<<mid<<endl;
		if(ok(mid)) l=mid;
		else r=mid;
	}
	printf("%d",ok(r)?r:l);
	return 0;
}