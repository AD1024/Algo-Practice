#include <iostream>
using namespace std;

int main(){
	int N,K;
	cin>>N>>K;
	int ans=0;
	int cur=0;
	for(int i=1;i<=N;++i){
		if(cur==K){
			++N;
			cur=0;
		}
		++ans;
		++cur;
	}
	cout<<ans;
	return 0;
}