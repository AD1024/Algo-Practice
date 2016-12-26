#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int a[10001];
bool idx[1000001];

bool judge(int a){
	if(a==2) return true;
	if(a<2) return false;
	if(a%2==0) return false;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0) return false;
	}
	return true;
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	memset(idx,false,sizeof(idx));
	int n;cin>>n;
	int k;cin>>k;
	int cnt=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(judge(a[k]-a[n-k+1])){
		cout<<"YES"<<"\n"<<a[k]-a[n-k+1];
	}else{
		cout<<"NO"<<"\n"<<a[k]-a[n-k+1];
	}
	return 0;
}
