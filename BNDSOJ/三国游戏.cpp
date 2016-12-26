#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int g[510][510];
bool used[510];

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=i+1;j<=N;++j){
			int k;cin>>k;
			g[i][j]=g[j][i]=k;
		}
	}
	//for(int i=1;i<=N;++i) sort(g[i].begin(),g[i].end());
	int ans=-100;
	for(int i=1;i<=N;++i){
		int a,b;
		a=b=0;
		for(int j=1;j<=N;++j){
			if(g[i][j]>a){
				b=max(a,b);
				a=g[i][j];
			}else{
				b=max(b,g[i][j]);
			}
			ans=max(ans,b);
		}
	}
	putchar('1');putchar('\n');
	cout<<ans;
	return 0;
}