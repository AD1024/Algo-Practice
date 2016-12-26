#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char list[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

 int main(){
 	int m,r;
 	int idx[256];
 	cin>>m>>r;
 	cout<<m<<'=';
 	int t,cnt=0;;
 	int n=r;
 	while(m!=0){
 		t=m%n;
 		m/=n;
 		if(t<0){
 			t-=n;
 			m++;
		 }
		 idx[cnt++]=t;
	 }
	 for(int i=cnt-1;i>=0;i--){
	 	cout<<list[idx[i]];
	 }
	 printf("(base%d)",n);
	 return 0;
 }