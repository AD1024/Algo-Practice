#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

string a,b;
bool sw=false;
int type=-1;
int m,n;
const int POW10[7]={1,10,100,1000,10000,100000};
inline int _stoi(string x){
	int ret=0;
	reverse(x.begin(),x.end());
	for(int i=0;i<x.size();++i){
		ret+=(x[i]-'0')*POW10[i];
	}
	return ret;
}

int main(){
	char str[10001];
	cin>>str;
	for(int i=0;i<strlen(str);++i){
		if(str[i]>='0' && str[i]<='9'){
			if(!sw){
				a+=str[i];
			}else{
				b+=str[i];
			}
		}else {
			sw=true;
			switch(str[i]){
				case '+':type=0;break;
				case '-':type=1;break;
				case '*':type=2;break;
				case '/':type=3;break;
			}
		}
	}
	m=_stoi(a);
	n=_stoi(b);
	switch(type){
		case 0:cout<<m+n;break;
		case 1:cout<<m-n;break;
		case 2:cout<<m*n;break;
		case 3:cout<<m/n;break;
	}
	return 0;
}