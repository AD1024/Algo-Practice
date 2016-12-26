#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 0xffffff;
const unsigned int INF = 2>>32;
int w[MAXN];

bool cmp(int a,int b){
	return a>b;
}


int main(){
	int maxt=-100;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t,v;
		cin>>t>>v;
		maxt=max(maxt,t);
		w[i]=v;
	}
	sort(w+1,w+n+1,cmp);
	int ans=0;
	for(int i=1;i<=maxt;i++){
		ans+=w[i];
	}
	cout<<ans<<"\n";
	return 0;
}
