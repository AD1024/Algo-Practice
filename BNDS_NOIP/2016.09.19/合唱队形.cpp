#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1001];
int f1[1001];
int f2[1001];
int N;
int main(){
	freopen("chorus.in","r",stdin);
	freopen("chorus.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
		f1[i]=f2[i]=1;
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<i;++j){
			if(a[j]<a[i] && f1[i]<f1[j]+1){
				f1[i]=f1[j]+1;
			}
		}
	}
	for(int i=N;i>=1;--i){
		for(int j=N;j>i;--j){
			if(a[i]>a[j] && f2[i]<f2[j]+1){
				f2[i]=f2[j]+1;
			}
		}
	}
	int ans=-1;
	for(int i=1;i<=K;++i){
		ans=max(ans,f1[i]+f2[i]-1);
	}
	cout<<N-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}