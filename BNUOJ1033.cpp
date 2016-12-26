#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10001;

vector<int> g[MAXN];

int main(){
	int N;
	cin>>N;
	int p;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&p);
			if(p){
				g[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=N;++i){
		printf("%d: ",i);
		int flag=0;
		for(int j=0;j<g[i].size();++j){
			if(!flag){
				printf("%d",g[i][j]);
				++flag;
			}else{
				printf(" %d",g[i][j]);
			}
		}
		cout<<endl;
	}
	return 0;
}