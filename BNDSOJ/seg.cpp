#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

string x;

int main(){
	cin>>x;
	string k=x;
	reverse(x.begin(),x.end());
	if(x==k){
		puts("yes");
	}else{
		puts("no");
	}
}