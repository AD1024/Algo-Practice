#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

struct P{
	int v,c;
}list[1001];

int ans=0;
vector<int> u[31];
vector<int> n[31];
int M,N;
int dp[40][10001];
int g[40][10001];
bool used[31];
//void f(int tot,int )



int main(){
	cin>>M>>N;
	int r;
	for(int i=1;i<=N;++i){
		cin>>list[i].c;
	}
	for(int i=1;i<=N;++i){
		cin>>r;
		list[i].v=r-list[i].c;
	}
	for(int i=1;i<=N;++i){
		for(int j=list[i].c;j<=M;++j){
			//dp[i][j]=max(dp[i-1][j],dp[i-1][v-list[i].w]+list[i].v);
			if(dp[i-1][j]>dp[i-1][j-list[i].c]+list[i].v){
				g[i][j]=0;
				dp[i][j]=dp[i-1][j];
			}else{
				g[i][j]=1;
				dp[i][j]=dp[i-1][j-list[i].c]+list[i].v;
			}
		}
	}
	cout<<dp[N][M]<<endl;
	int i=N;int v=M;
	while(i>0){
		if(g[i][v]){
			printf("%d\n",i);
			v-=list[i].v;
		}
		--i;
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>r;
			if(r==1){
				u[i].push_back(j);
			}else if(r==2){
				n[i].push_back(j);
			}
		}
	}
	return 0;
}