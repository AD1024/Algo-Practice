#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double x1,_y1,x2,y2,x3,y3;

int main(){
	cin>>x1>>_y1>>x2>>y2>>x3>>y3;
	double ans = 1.0/2.0*fabs((x1*y2+x2*y3+x3*_y1)-(x2*_y1+x3*y2+x1*y3));
	printf("%.2lf",ans);
	return 0;
}