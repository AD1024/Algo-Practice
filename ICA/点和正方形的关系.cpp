#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

double x,y;

int main(){
	while(cin>>x>>y){
		if(x>=-1 && x<=1 && y>=-1 && y<=1){
			puts("yes");
		}else puts("no");
	}
	return 0;
}