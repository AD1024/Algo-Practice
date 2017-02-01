#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

inline int gcd(int x,int y){
	while(x^=y^=x^=y%=x);
	return y;
}

inline int lcm(int x,int y){
	return x*y/gcd(x,y);
}

int main(){
	int a,b,c,d;
	// a/b + c/d;
	cin>>a>>b>>c>>d;
	int x = lcm(b,d);
	int mul = x / d;
	c *= mul;
	mul = x / b;
	a *= mul;
	int ans1 = c + a;
	int mod = gcd(ans1,x);
	ans1 /= mod;
	x /= mod;
	cout<<ans1<<" "<<x;
	return 0;
}