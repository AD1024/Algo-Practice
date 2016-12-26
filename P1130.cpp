#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010][2010];
int main(){
	int g[1010][2010];
	int M,N;
	cin>>N>>M;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			cin>>g[i][j];
		}
	}
	int ans=100000000;
	for(int i=1;i<=M;i++){
		a[i][1]=g[i][1];
	}
	for(int j=2;j<=N;++j)
		for(int i=1;i<=M;++i){
			if(i==1){
				a[i][j]=g[i][j]+min(a[M][j-1],a[i][j-1]);
			}else{
				a[i][j]=g[i][j]+min(a[i-1][j-1],a[i][j-1]);
			}
		}
	// cout<<endl;
	// for(int i=1;i<=M;i++){
	// 	for(int j=1;j<=N;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	for(int i=1;i<=M;i++){
		ans=min(ans,a[i][N]);
	}
	cout<<ans;
	return 0;
}