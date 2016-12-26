#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX(x,y) x>y?x:y
int a[101];
int main(){
	int N;
	cin>>N;
	int maxn=-100;
	for(int i=1;i<=N;++i){
		int m,n;cin>>m>>n;
		a[m]+=n;
		maxn=MAX(maxn,m);
	}
	cin>>N;
	for(int i=1;i<=N;++i){
		int m,n;cin>>m>>n;
		a[m]+=n;
		maxn=MAX(maxn,m);
	}
	for(int i=maxn;i>=0;--i){
		if(a[i]==0) continue;
		if(a[i]==1){
			printf("x%d",i);
		}else if(i!=0){
			printf("%dx%d",a[i],i);
		}else{
			printf("%d",a[i]);
		}
		if(i!=0) putchar('+');
	}
	return 0;
}