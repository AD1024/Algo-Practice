#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
	string a;
	getline(cin,a);
	int len=a.size()-1;
	for(int i=0;i<(len+1)/2;++i){
		if(a[i]!=a[len-i]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}