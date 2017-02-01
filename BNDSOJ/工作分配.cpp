#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w[20][20];

int ans = 0;
bool vis[20];
int N;

void f(int dep,int k){
	if(dep > N){
		ans = max(ans,k);
	}else{
		for(int i=1;i<=N;++i){
			if(!vis[i]){
				vis[i] = true;
				f(dep+1,k + w[dep][i]);
				vis[i] = false;
			}
		}
	}
}

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>w[i][j];
		}
	}
	f(1,0);
	cout<<ans;
	return 0;
}