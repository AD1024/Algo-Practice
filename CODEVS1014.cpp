#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int gg;
	cin>>gg;
	cin>>n;
	int a[10001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int w[10001];
	memset(w,0,sizeof(w));
	for(int i=1;i<=n;i++){
		for(int j=gg;j>=a[i];j--){
			w[j]=max(w[j],w[j-a[i]]+a[i]);
		}
	}
	cout<<gg-w[gg];
	return 0;
}
