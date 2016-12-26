#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//#define OJ
int f[10001][301];
int a[10000];
int N,M;

int main(){
	#ifdef OJ
	freopen("cowrun.in","r",stdin);
	freopen("cowrun.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	f[0][0]=0;
	for(int i=1;i<=N;++i){
		f[i][0]=f[i-1][0];
		for(int j=1;j<=M;++j){
			if(i>=j){
				f[i][0]=max(f[i-j][j],f[i][0]);
			}
			f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]);
		}
	}
	cout<<f[N][0];
	#ifdef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}