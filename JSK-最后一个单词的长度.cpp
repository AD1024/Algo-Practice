#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	int len = s.length();
	int s1=-1,s2=-1;
	for(int i=0;i<len;i++){
		if(s[i]==' '){
			s1=s2;
			s2=i;
		}
	}
	if(s2==-1){
		cout<<len<<"\n";
	}else if(s2==len-1){
		cout<<len-s1-2<<endl;
	}else{
		cout<<len-s2-1;
	}
	return 0;
}
