#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double tot;double a;
int N;

int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a;
		tot+=a;
	}
	printf("%.2f",tot/double(N));
	return 0;
}