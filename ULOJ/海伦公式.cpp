#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

double a,b,c;

int main(){
	cin>>a>>b>>c;
	double p = (a+b+c) / 2.0;
	double s = sqrt(p * (p-a) * (p-b) * (p-c));
	printf("%.5f\n",s);
	return 0;
}