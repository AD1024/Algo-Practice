#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int aa[9]={1,2,3,4,5,6,7,8,9};
	do{
		int a=100*aa[0]+10*aa[1]+aa[2];
		int b=100*aa[3]+10*aa[4]+aa[5];
		int c=100*aa[6]+10*aa[7]+aa[8];
		if(3*a*2==1*b*3 && b*3*1==c*2*1 && c*2*1==a*3*2){
			printf("%d %d %d\n",a,b,c);
		}
	}while(next_permutation(aa,aa+9));
	return 0;
}
