#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

string a;

inline bool gg(char x){
	return x>='a' && x<='z';
}
#define PP(x) x-32
int main(){
	getline(cin,a);
	for(int i=0;i<a.size();++i){
		if(gg(a[i])){
			a[i]=PP(a[i]);
		}
	}
	cout<<a;
	return 0;
}