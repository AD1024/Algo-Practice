#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[10001];

int main(){
	int N;
	cin>>N;
	int ans=0;
	for(int i=0;i<N;++i){
		cin>>a[i];
		ans+=a[i];
	}
	int sum=0;
	for(;;){
		sum=0;
		sort(a,a+N);
		if(a[N-1]==a[0]) break;
		for(int i=N;i>=0;--i){
			if(a[i]>a[i-1]){
				a[i]=a[i]-a[i-1];
			}
		}
		for(int i=0;i<N;++i){
			sum+=a[i];
		}
		//ans=min(ans,sum);
		ans=sum;
	}
	cout<<ans<<endl;
	return 0;
}