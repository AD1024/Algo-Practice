#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[8][20]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
#define ret return
#define wojiubuxiemain main

inline int parse(int y,int m,int d){
	if(m==1 || m==2){
		--y;m+=12;
	}
	int c=y/100;
	y=y-c*100;
	int W=(c/4)-2*c+(y+y/4)+(13*(m+1)/5)+d-1;
	while(W<0)W+=7;W%=7;
	return W;
}

int wojiubuxiemain(){
	int y,m,d;
	cin>>y>>m>>d;
	puts(str[parse(y,m,d)]);
	ret 0;
}