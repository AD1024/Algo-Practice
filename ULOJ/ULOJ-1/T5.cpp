#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
using namespace std;

int s;

int main(){
	cin>>s;
	for(int i=sqrt(s);i>=1;--i){
		if(i * (s/i) == s){
			cout<<i<<" "<<s/i<<endl;
			return 0;
		}
	}
}
