#include <iostream>
using namespace std;

// Recursive

int GCD(int x,int y){
	if(x==0) return y;
	return GCD(y%x,x);
}

// Loop (Recommended);
inline void GCD(int x,int y){
	while(x^=y^=x^=y%=x);return y;
}