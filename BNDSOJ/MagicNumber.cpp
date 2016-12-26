#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

string a;

int main(){
	cin>>a;
	for(int i=0;i<a.size();++i){
		if(a[i]=='1' && a[i+1]=='4' && a[i+2]=='4'){
			a[i]=a[i+1]=a[i+2]='*';
		}else if(a[i]=='1' && a[i+1]=='4'){
			a[i]=a[i+1]='*';
		}else if(a[i]=='1'){
			a[i]='*';
		}
	}
	for(int i=0;i<a.size();++i){
		if(a[i]!='*'){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}