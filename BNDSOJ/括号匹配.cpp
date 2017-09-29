#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

stack<char> s;

string a;

int main(){
	ios::sync_with_stdio(false);
	cin>>a;
	for(int i=0;i<a.length();++i) {
		if(a[i] == '[' or a[i] == '(') {
			s.push(a[i]);
		}else{
			if(a[i] == ']'){
				if(s.size() == 0 or s.top() != '[') {
					puts("NO");
					return 0;
				}else s.pop();
			}else if(a[i] == ')') {
				if(s.size() == 0 or s.top() != '(') {
					puts("NO");
					return 0;
				}else s.pop();
			}
		}
	}
	if(s.size() != 0)
		puts("NO");
	else
		puts("YES");
	return 0;
}