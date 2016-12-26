#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int X,Y,N;

int main(){
	cin>>N>>X>>Y;
	int tot = ceil(double(Y)/double(X));
	cout<<((N-tot)>0?N-tot:0);
	return 0;
}