#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 400;
int x[MAXN],y[MAXN];
int x1[MAXN],y1[MAXN];
int tot=0;
int n;
int c=1;
int ans[MAXN][MAXN];
inline void output(){
	if(tot<=3){
		for(int j=1;j<=n;j++){
			cout<<x[j];
			if(j!=n) cout<<" ";
		}
		cout<<endl;
	}
	return;
}

void dfs(int k){
	if(k>n){
		tot++;
		output();
	}else{
	for(int i=1;i<=n;i++){
		if(!(y[i] || x1[i+k] || y1[k-i+n])){
			x[k]=i;
			x1[k+i]=y[i]=y1[k-i+n]=1;
			dfs(k+1);
			x1[k+i]=y[i]=y1[k-i+n]=0;
		}
	}
}
	return;
}

int main(){
	memset(x,-1,sizeof(x));
	memset(x1,0,sizeof(x1));
	memset(y1,0,sizeof(y1));
	memset(y,0,sizeof(y));
	cin>>n;
	dfs(1);
	cout<<tot;
	return 0;
}
