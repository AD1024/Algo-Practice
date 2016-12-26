#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
using namespace std;

struct Stack{
	int t;
	int bottom;
	int a[10001];
	Stack(){
		memset(a,0,sizeof(a));
		t=bottom=0;
	}
	void push(int x){
		a[++t]=x;
	}
	void pop(){
		if(t==bottom) return;
		else{
			--t;
		}
	}
	int size(){
		return t-bottom;
	}
	int top(){
		return a[t];
	}
};

int main(){
	Stack s;
	for(int i=0;i<10;++i){
		s.push(i);
	}
	while(s.size()){
		cout<<s.top()<<' ';
		s.pop();
	}
	return 0;
}