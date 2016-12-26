#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define ls(x) x<<1
#define rs(x) (x<<1)+1

string tree[100001];
int N;

void build(int i){
	if(tree[i].size()==1){
		return;
	}
	int len = tree[i].size()>>1;
	tree[ls(i)]=tree[i].substr(0,len);
	tree[rs(i)]=tree[i].substr(len,len);
	build(ls(i));
	build(rs(i));
}

inline int judge(string s){
	bool have1,have0=false;
	have1=have0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1' && !have1) have1=true;
		else if(!have0) have0=true;
	}
	if(have0 && have1) return 2;
	else if(have1) return 1;
	else return 0;
}

void post(int x){
	switch(judge(tree[x])){
		case 1: putchar('I');break;
		case 0: putchar('B');break;
		case 2: putchar('F');break;
	}
	post(ls(x));
	post(rs(x));
}

int main(){
	cin>>N;
	cin>>tree[1];
	build(1);
	post(1);
	return 0;
}
