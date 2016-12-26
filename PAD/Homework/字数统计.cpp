#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int ans[11];

inline bool gg(char x){
	return x>='0' && x<='9';
}
#define PP(x) x-'0'

string str;

int main(){
	getline(cin,str);
	for(int i=0;i<str.size();++i){
		if(gg(str[i])){
			ans[PP(str[i])]++;
		}
	}
	for(int i=0;i<=9;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}