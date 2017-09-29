#include <iostream>
#include <cstdio>
using namespace std;

int T;

int main(){
	scanf("%d", &T);
	int a,b;
	while(T--){
		scanf("%d%d",&a,&b);
		if (a == 0 || b == 0) 
			printf("%d\n",a-b);
		else 
			printf("%d\n",a-b-2);
	}
	return 0;
}