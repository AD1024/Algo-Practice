#include <iostream>
using namespace std;

int main(){
	int l,r;
	cin>>l>>r;
	int ans=0;
	for(int i=l;i<=r;++i){
		if(i&1){
			ans+=i;
		}
	}
	cout<<ans;
	return 0;
}