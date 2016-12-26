#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 100010;

inline int MAX(int x,int y){
	return x>y?x:y;
}

int ans[MAXN];
int tmp;
int N,x,t,k;
int out=-100;

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>x>>t;
		ans[x]=t;
		while(cin>>k){
			if(!k) break;
			ans[x]=MAX(ans[x],t+ans[k]);
			out=MAX(out,ans[x]);
		}
	}
	cout<<out<<"\n";
	return 0;
}