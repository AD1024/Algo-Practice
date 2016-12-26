#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//f[i]=min(f[i-ai]+1)
#define INF 0x3f3f3f3f
int a[10001];

int main(){
	int N;
	cin>>N;
	int l,r,num;
	cin>>l>>r>>num;
	for(int i=0;i<=N;i++){
		a[i]=INF;
	}
	for(int i=1;i<=num;i++){
		int pos;cin>>pos;
		a[pos]=1;
	}
	a[0]=0;
	for(int i=1;i<=N;i++){
		for(int j=l;j<=r && j<i;j++){
			a[i]=min(a[i-j]+1,a[i]);
		}
	}
	cout<<a[N];
	return 0;
}