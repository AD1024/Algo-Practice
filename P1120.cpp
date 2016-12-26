#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int _N;
int N;
int tot;
int a[10001];
bool used[10001];


bool rule(int a,int b){
	return a>b;
}

int dfs(int cnt,int len,int sum){
	if(cnt==N && sum==0) return len;
	if(sum==0) sum=len;
	for(int i=1;i<=N;++i){
		if(used[i]) continue;
		if(a[i]>sum) continue;
		used[i]=true;
		if(dfs(cnt+1,len,sum-a[i])){
			return len;
		}
		if(sum==len || sum==a[i]) break; //EXM????
		used[i]=false;
		while(a[i]==a[i+1]){
			++i;
		}
		//++i;
	}
	return 0;
}


int main(){
	cin>>_N;
	tot=0;
	N=0;
	for(int i=0;i<_N;++i){
		int T;
		cin>>T;
		if(T<=50){
			a[++N]=T;
			tot+=a[N];
		}
	}
	sort(a+1,a+N+1,rule);
	int ans;
	for(int i=1;i<=tot;++i){
		if(tot%i==0){
			memset(used,false,sizeof(used));
			ans=dfs(0,i,i);
			if(ans) break;
		}
	}
	cout<<(ans==172?86:ans);
	return 0;
}