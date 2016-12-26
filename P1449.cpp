#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;

int main(){
	char tt;
	while((tt=getchar()) && tt!='@'){
		if(tt>='0' && tt<='9'){
			int ps = tt-'0';
			while((tt=getchar()) && tt>='0' && tt<='9'){
				ps=ps*10+tt-'0';
			}
			s.push(ps);
		}
		if(tt=='+' || tt=='-' || tt=='*' || tt=='/'){
			int opta = s.top();s.pop();
			int optb = s.top();s.pop();
			switch(tt){
				case '+':s.push(opta+optb);break;
				case '-':s.push(optb-opta);break;
				case '*':s.push(optb*opta);break;
				case '/':s.push(optb/opta);break;
			}
		}
	}
	cout<<s.top();
	return 0;
}