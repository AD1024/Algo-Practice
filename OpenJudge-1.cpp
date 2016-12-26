#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int T;
	cin>>T;
	int N;
	int ans;
	while(T--){
		cin>>N;
		ans=0;
		while(N){
			int t=N%2;
			if(t) ans++;
			N/=2;
		}
		cout<<ans<<"\n";
	}
	return 0;
}