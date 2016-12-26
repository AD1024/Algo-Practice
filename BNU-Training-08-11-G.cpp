#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N;
long long a[100010],b[100010];
long long cnt=0;
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	for(int i=0;i<N;++i){
		cin>>b[i];
	}
	for(int i=0;i<N;++i){
		if(b[i]==1 || b[i]>a[i]*2){
			cnt--;
		}else{
			long long s=b[i]/2;
			cnt+=(s*(b[i]-s));
		}
	}
	cout<<cnt;
	return 0;
}