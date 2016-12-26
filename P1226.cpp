#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long

inline long long power1(ll a,ll b,ll c){
	ll ans = 1;
	while(b){
		if(b&1)
			ans=(ans*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return ans;
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<a<<'^'<<b<<" mod "<<c<<'='<<power1(a,b,c);
	return 0;
}
