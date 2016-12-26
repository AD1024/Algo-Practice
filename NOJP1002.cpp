#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char a[3],b[3];
char k;
int w[100];
int main(){
	int T;
	cin>>T;
	getchar();
	for(int i=1;i<=10;++i){
		w[i]=i;
	}
	w['J']=11;w['K']=13;
	w['Q']=12;w['A']=14;
	while(T--){
		k=getchar();
		cin>>a>>b;
		if(a[1]==k){
			puts("YES");
		}else if(b[1]==k){
			puts("NO");
		}else if(w[a[0]]>w[b[0]]){
			puts("YES");
		}else puts("NO");
	}
	return 0;
}