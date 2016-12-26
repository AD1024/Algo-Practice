#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

string a,b;

inline void add(){
	int la=a.length();
	int lb=b.length();
	if(la<lb) swap(a,b);
	int sum=0;
	for(int i=a.length()-1,j=b.length()-1;i>=0;--i,--j){
		sum+=a[i]-'0';if(j>=0) sum+=b[j]-'0';
		a[i]=sum%10+'0';
		sum/=10;
	}
	if(sum){
		a='1'+a;
	}
}

int main(){
	cin>>a>>b;
	add();
	cout<<a;
	return 0;
}