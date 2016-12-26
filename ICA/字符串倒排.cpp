#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

string x;
stack<string> s;

int main(){
	while(cin>>x){
		s.push(x);
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}