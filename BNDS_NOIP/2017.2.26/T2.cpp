#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[310][310];int a[310];
// f[j][i] = j * |a[i] - a[i+j-1]| f[j][i] = max(f[j][i],f[k][j]+f[i-k][j+k])
int N;

int main(){
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];f[i][1] = a[i];
	}
	for(int j=2;j<=N;++j){
		for(int i=1;i<=N-j+1;++i){
			f[i][j] = abs(a[i]-a[i+j-1])*j;
			for(int k=1;k<j;++k) f[i][j] = max(f[i][j],f[i][k]+f[i+k][j-k]);
		}
	}
	/*
	for(int i=2;i<=N;++i){
		for(int j=1;j<=N-i+1;++j){
			f[j][i] = j*abs(a[i]-a[i+j-1]);
			for(int k=1;k<i;++k){
				f[j][i] = max(f[j][i],f[i-k][k+j]+f[k][j]);
			}
		}
	}*/
	int ans = -1;
	for(int i=1;i<=N;++i) ans = max(ans,f[i][N]);
	cout<<ans;
	return 0;
}