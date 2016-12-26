#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

#define pi acos(-1)

const double tot = 20.0*1000; 

int main(){
	int H,R;cin>>H>>R;
	double S = pi*R*R;
	double V = S*(double)H;
	int ans = ceil(tot/V);
	cout<<ans;
	return 0;
}