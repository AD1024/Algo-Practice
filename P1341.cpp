#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10001;
#define INF 0x3f3f3f3f
bool map[200][200];

int N;int K;
char ans[10001];
bool found=false;
bool vis[100];
void dfs(char u,char v,int idx){
	ans[idx]=v;
	if(idx==K){
		for(int i=1;i<=N;++i){
			cout<<ans[i];
		}
		found=1;
		return;
	}
	char i='A';char j='a';
	while(i<='Z' && j<='z'){
		if(!vis[i] && map[v][i]){
			vis[i]=true;
			dfs(v,i,idx+1);
			vis[i]=false;
		}
		++i;
		if(found) return;
		if(!vis[j] && map[v][j]){
			vis[j]=true;
			dfs(v,j,idx+1);
			vis[j]=false;
		}
		++j;
		if(found) return;
	}
}

bool Index[100];
int main(){
	char str[2];
	cin>>N;
	char minm=127;
	for(int i=0;i<N;i++){
		cin>>str;
		map[str[0]][str[1]]=map[str[1]][str[0]]=true;
		if(!Index[str[0]]){
			if(str[0]<minm) minm=str[0];
			K++;
			Index[str[0]]=true;
		}
		if(!Index[str[1]]){
			if(str[1]<minm) minm=str[1];
			K++;
			Index[str[1]]=true;
		}
	}
	vis[minm]=true;
	dfs(minm,minm,1);
	return 0;
}