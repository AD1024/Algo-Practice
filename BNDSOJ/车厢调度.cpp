#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack<int> s;
int a=0,upper=-1;
int main(){
	int N;cin>>N;bool isb=false;
	for(int i=1;i<=N;++i){
		cin>>a;
		if(a > upper){
			for(int j=upper+1;j<=a;++j){
				s.push(j);
			}
			upper=a;
		}
		if(a <= upper){
			// cout<<s.top()<<" "<<a<<endl;
			if(s.top() == a){
				s.pop();
			}else{
				
				isb=true;
				break;
			}
		}
	}

	if(isb){
		puts("NO");
	}else{
		puts("YES");
	}
}