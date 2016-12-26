#include <iostream>
using namespace std;
typedef long long ll;

ll x=1;
int main(){
	ll N,X;
	cin>>X>>N;
	for(int i=0;i<N;++i){
		x+=X*x;
	}
	cout<<x;
	return 0;
}