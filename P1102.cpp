#include <iostream>
using namespace std;

int main(){
	int N,C;
	cin>>N>>C;
	int a[200001];
	int f[1000000];
	for(int i=1;i<=N;i++){
		cin>>a[i];
		f[a[i]]+=1;
	}
	int ans=0;
	for(int i=1;i<=N;i++){
		if(a[i]>C){
			ans+=f[a[i]-C];
		}
	}
	cout<<ans;
	return 0;
}