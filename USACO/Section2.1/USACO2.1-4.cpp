/*
ID: ccodera1
LANG: C++
TASK: holstein
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool vis[1000];

int val[20][1010];

int need[50];

int V;int G;

bool ans[50];

int o[50];
int oidx = 0x3f3f3f3f;

inline bool ok(int a[]){
	for(int i=1;i<=V;++i){
		if(a[i]<need[i]) return false;
	}
	return true;
}

int cnt = 1;

void dfs(int idx,int a[]){
	if(ok(a) && cnt<oidx){
		oidx = cnt;
		for(int i=1;i<idx;++i){
			o[i] = ans[i];
		}
		return;
	}else if(idx>G){
		return;
	}else{
		vis[idx] = true;
		int stub[50];
		ans[idx] = true;
		for(int i=1;i<=V;++i){
			stub[i] = a[i];
			a[i] += val[idx][i];
		}
		++cnt;
		dfs(idx+1,a);
		--cnt;
		ans[idx] = false;
		vis[idx] = false;
		memcpy(a,stub,sizeof(stub));
		dfs(idx+1,a);
	}
}

vector<int> v;

int main(){
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	cin>>V;
	for(int i=1;i<=V;++i){
		cin>>need[i];
	}
	cin>>G;
	for(int i=1;i<=G;++i)
		for(int j=1;j<=V;++j){
			cin>>val[i][j];
		}
	int a[50];
	memset(a,0,sizeof(a));
	dfs(1,a);oidx--;
	cout<<oidx<<" ";
	int cur=0;
	for(int i=1;i<=G;++i){
		if(o[i]){
			v.push_back(i);
		}
	}
	for(int i=0;i<v.size()-1;++i){
		cout<<v[i]<<" ";
	}
	cout<<v[v.size()-1]<<endl;
	return 0;
}