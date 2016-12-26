#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[7]={0,20,10,5,3,2,1};
int ans=0x3f3f3f3f;
int N;
void dfs(int idx,int sum){
	if(sum>N){
		return;
	}else if(sum==N){
		cout<<idx;
		exit(0);
	}else{
		for(int i=1;i<=6;++i){
			dfs(idx+1,sum+a[i]);
		}
	}
}
int main(){
	freopen("weight.in","r",stdin);
	freopen("weight.out","w",stdout);
	cin>>N;
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}