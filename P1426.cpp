#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

int main(){
	double dis,range;
	cin>>dis>>range;
	double left = dis-range;
	double right = dis+range;
	double dist=0;
	double speed=7.0;
	do{
		dist+=speed;
		speed*=0.98;
	}while(dist<left);
	if(dist+speed<=right){
		cout<<"y";
	}else{
		cout<<"n";
	}
	return 0;
}
