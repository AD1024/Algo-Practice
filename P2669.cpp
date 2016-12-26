#include <iostream>
using namespace std;

int main(){
	int K;
	cin>>K;
	int ans=0;
	int cur=1;
	int i,j;
	int k=1;
	for(i=1;;++i){
		if(((1+i)*i)>>1 >= K) break;
	}
	if(((i+1)*i)>>1==K){
		for(j=1;j<=i;++j){
			ans+=j*j;
		}
	}else{
		
	}
	cout<<ans;
	return 0;
}