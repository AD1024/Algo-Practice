#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int N;
	cin>>N;
	bool vis[51][51];
	memset(vis,false,sizeof(vis));
	int sum=0;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			int k;cin>>k;
			if(i==j || N-i+1==j){
				if(!vis[i][j]){
					vis[i][j]=true;
					sum+=k;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}