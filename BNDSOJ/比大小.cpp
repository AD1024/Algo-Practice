#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

inline void gt(string a,string b){
	if(a.size()>b.size()){
		cout<<a;
	}else if(a.size()<b.size()){
		cout<<b;
	}else{
		for(int i=0;i<a.size();++i){
			if(a[i]>b[i]){
				cout<<a;
				return;
			}else if(b[i]>a[i]){
				cout<<b;
				return;
			}
		}
		cout<<a;return;
	}
}

int main(){
	string a,b;
	cin>>a>>b;
	gt(a,b);
	return 0;
}