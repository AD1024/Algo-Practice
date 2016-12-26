#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

char a[1001];
char b[1001];

int main(){
	getline(cin,a);
	getline(cin,b);
	char *p;
	if(p=strstr(a,b)){
		cout<<(int)(p-a+1);
	}else cout<<-1;
	return 0;
}