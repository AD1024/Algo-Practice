/*
ID: ccodera1
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
#include <cstdlib>
using namespace std;

int B;
char a[10100];
int stub[10100];
int len;

const char list[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};

inline void parse(int x){
	int cur=0;
	while(x){
		a[cur++]=list[x%B];
		x/=B;
	}
	len=cur;
	for(int i=0;i<cur>>1;++i){
		swap(a[i],a[cur-i-1]);
	}
}

inline bool ok(){
	for(int i=0;i<len>>1;++i){
		if(a[i]!=a[len-i-1]) return false;
	}
	return true;
}

inline void file(){
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
}

int main(){
	file();
	cin>>B;
	for(int i=1;i<=300;++i){
		int j=i*i;
		parse(j);
		if(ok()){
			parse(i);
			for(int i=0;i<len;++i){
				cout<<a[i];
			}
			putchar(' ');
			parse(j);
			for(int i=0;i<len;++i){
				cout<<a[i];
			}
			puts("");
		}
	}
	return 0;
}