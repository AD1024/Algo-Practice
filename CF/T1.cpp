#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

vector<int> v;

int main(){
	int N;
	cin>>N;
	string a;cin>>a;
	int c=0;
	for(int i=0;i<a.size();){
		c=0;
		if(a[i]=='B'){
			char k=a[i];
			while(k==a[i]){
				++i;
				++c;
			}
			v.push_back(c);
		}else ++i;
	}
	if(v.size()>=1){
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}
	}else{
		puts("0");
	}
	return 0;
}