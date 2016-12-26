#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

inline int gcd(int x,int y){
	while(x^=y^=x^=y%=x);return y;
}

inline int lcm(int x,int y){
	return x*y/gcd(x,y);
}

