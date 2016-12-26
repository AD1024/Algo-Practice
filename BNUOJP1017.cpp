#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


int ans[10001];
int N,M;
bool vis[10001];
int ct=0;
void dfs(int x){
	if(x>N){
		for(int i=1;i<=N;++i){
			printf("%d",ans[i]);
		}
		puts("");
		ct++;
		return;
	}
	int stk=0;
	for(int i=1;i<=N && stk<=M;++i){
		if(!vis[i]){
			vis[i]=true;
			ans[x]=i;
			stk++;
			dfs(x+1);
			vis[i]=false;
		}
	}
}


int main(){
	cin>>N>>M;
	dfs(1);
	printf("%d",ct);
	return 0;
}
