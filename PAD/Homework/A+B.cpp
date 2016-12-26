#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int r=a%3;
	a-=r;
	a/=3;
	b+=a;c+=a;
	r=b%3;
	b-=r;
	b/=3;
	a+=b;c+=b;
	r=c%3;
	c-=r;
	c/=3;
	a+=c;b+=c;
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}