#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
bool color;

int main(){
	int x,y;cin>>x>>y;
	char ch;
	for(int i=1;i<=x;++i){
		for(int j=1;j<=y;++j){
			cin>>ch;
			if(ch == 'C' || ch == 'M' || ch == 'Y'){
				color = true;
			}
		}
	}
	if(color){
		puts("#Color");
	}else{
		puts("#Black&White");
	}
	return 0;
}