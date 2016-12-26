#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
	long long N;
	while(cin>>N){
		long long i=1;
		long long ans=0;
		while(i<=N){
			i<<=1;
			ans++;
			if(i==N) break;
			else if(i<<1>N){
				ans+=1;break;
			}
		}
		cout<<ans<<"\n";
	}
	puts("0");
	return 0;
}