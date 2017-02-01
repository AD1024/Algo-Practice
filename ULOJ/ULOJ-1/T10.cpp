#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define MAXN 50001

int a[MAXN];
int l,r,p;
int N,M;
long long pre[MAXN];


int main(){
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=N;++i){
		pre[i] = pre[i-1] + a[i];
	}
	long long t;
	while(M--){
		scanf("%d%d%d",&l,&r,&p);
		if(r-l+1>p) puts("0");
		else{
			long long ans = MAXN;
			for(int i=l;i<=r;++i){
				for(int j=i;j<=r;++j){
					t = (pre[j] - pre[i-1])%p;
					ans = min(ans,t);
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}