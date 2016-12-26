#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char str1[1000001],str2[10001];

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%s%s",str1,str2);
		if(strstr(str1,str2)!=NULL){
			int pos=(strstr(str1,str2))-str1+1;
			printf("%d\n",pos);
		}else{
			puts("-1");
		}
	}
	return 0;
}