#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	double ccnt=0.0;
	double son=0.0;
	int n;
	cin>>n;
	while(n--){
		double cre,sc;
		cin>>cre>>sc;
		son+=cre*sc;
		ccnt+=cre;
	}
	printf("%.2f",(double)son/ccnt);
	return 0;
}