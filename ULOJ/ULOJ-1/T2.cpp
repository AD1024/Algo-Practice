#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

int N;
string x;
int ans;

int l,r;
int main(){
	cin>>N;
	cin>>x;
	l = r = -1;
	for(int i=0;i<x.length();++i){
		if(x[i] == '>'){
			l = i;break;
		}
	}
	for(int i=x.length()-1;i>=0;--i){
		if(x[i] == '<'){
			r = i;
			break;
		}
	}
	if(l == -1 || r == -1){
		cout<<N;
	}else{
		cout<<N-(r-l+1);
	}
	return 0;
}