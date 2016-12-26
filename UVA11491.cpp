#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n,d;
	while(~scanf("%d%d",&n,&d) && n && d){
		char a[10010];
		getchar();
		int k=0;
		a[0]='0';
		for(int i=0;i<n;i++){
			char c=getchar();
			while(k>0 && k+(n-i)>n-d && a[k]<c) 
				k--;
			if(k<n-d){
				a[++k]=c;
			}
		}
		a[++k]='\0';
		puts(a+1);
	}
	return 0;
}