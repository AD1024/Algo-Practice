#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	double N;
	cin>>N;
	double sum=0.0;
	bool flag=false;
	for(double i=1;1.0/i>=N;i+=2){
		flag=!flag;
		sum+=(flag?(1.0/i):-(1.0/i));
	}
	printf("%.6lf\n",sum);
	return 0;
}