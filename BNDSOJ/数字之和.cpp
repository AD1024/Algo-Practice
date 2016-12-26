#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int N;int ans=0;
	cin>>N;
	while(N){
		ans+=N%10;
		N/=10;
	}
	cout<<ans;
	return 0;
}