#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10001];
int N;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	cin>>N;
	int tot=0;
	for(int i=1;i<=N;++i){
		cin>>a[i];
		tot+=a[i];
	}
	sort(a+1,a+1+N,cmp);
	int sum=0,cnt=0;
	for(int i=1;i<=N;++i){
		sum+=a[i];
		tot-=a[i];
		cnt+=1;
		if(sum>tot){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
