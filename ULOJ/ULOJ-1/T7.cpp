#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
using namespace std;


int x,y,z;

int main(){
	cin>>x>>y>>z;
	int a = x;
	int b = (y >> 1);
	int c = (z >> 2);
	int k = min(min(a,b),min(b,c));
	cout<<k+(k<<1)+(k<<2);
	return 0;
}